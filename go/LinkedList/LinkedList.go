package LinkedList

import (
	"errors"
	"fmt"
)

type Node[T any] struct {
	value T
	next  *Node[T]
}

type LinkedList[T any] struct {
	begin *Node[T]
	end   *Node[T]
}

func New[T any]() *LinkedList[T] {
	return &LinkedList[T]{begin: nil, end: nil}
}

func (list *LinkedList[T]) GetBegin() *Node[T] {
	return list.begin
}

func (list *LinkedList[T]) GetEnd() *Node[T] {
	return list.end
}

func (list *LinkedList[T]) Find(value T, equals func(a, b T) bool) (int, error) {
	if list.begin == nil {
		return -1, errors.New("invalid list for search")
	}

	current := list.begin
	for index := 0; current != nil; index++ {
		if equals(current.value, value) {
			return index, nil
		}
		current = current.next
	}

	return -1, errors.New("element not found")
}

func (list *LinkedList[T]) PushBack(value T) {

	node := &Node[T]{value: value, next: nil} // new node

	if list.begin == nil {
		list.begin = node
		list.end = node

		return
	}

	list.end.next = node
	list.end = node
}

func (list *LinkedList[T]) Insert(value T, position int) error {
	if list.begin == nil && position != 0 || position < 0 {
		return errors.New("invalid position for insertion")
	}

	node := &Node[T]{value: value, next: nil} // new node

	if list.begin == nil {
		list.begin = node
		list.end = node

		return nil
	}

	if position == 0 {
		node.next = list.begin
		list.begin = node

		return nil
	}

	current := list.begin
	for index := 0; current != nil && index < position-1; index++ {
		current = current.next
	}

	if current == nil {
		return errors.New("invalid position for insertion")
	}

	node.next = current.next
	current.next = node

	return nil
}

func (list *LinkedList[T]) Replace(value T, position int) error {
	if list.begin == nil || position < 0 {
		return errors.New("invalid position for insertion")
	}

	current := list.begin
	for index := 0; current != nil && index < position; index++ {
		current = current.next
	}

	if current == nil {
		return errors.New("invalid position for insertion")
	}

	current.value = value

	return nil
}

func (list *LinkedList[T]) Delete(position int) error {
	if list.begin == nil || position < 0 {
		return errors.New("invalid position for deletion")
	}

	current := list.begin

	if position == 0 {
		list.begin = current.next
		if list.begin == nil {
			list.end = nil
		}

		return nil
	}

	for index := 0; current != nil && index < position-1; index++ {
		current = current.next
	}

	if current == nil {
		return errors.New("invalid position for deletion")
	}

	if current.next.next == nil {
		current.next = nil
		list.end = current

		return nil
	}

	current.next = current.next.next

	return nil
}

func (list *LinkedList[T]) String() string {
	if list.begin == nil {
		return "[]"
	}

	result := "["

	current := list.begin
	for current != nil {
		result += fmt.Sprintf("%v", current.value)

		if current.next != nil {
			result += ", "
		}

		current = current.next
	}

	return result + "]"
}
