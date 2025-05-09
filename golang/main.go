package main

import (
	"fmt"
	"linkedlist/LinkedList"
)

func main() {
	list := LinkedList.New[int]()

	// push back
	list.PushBack(1)
	list.PushBack(2)
	list.PushBack(3)
	list.PushBack(4)
	list.PushBack(5)
	fmt.Println(list)

	// insert
	fmt.Println(list.Insert(-5, 5))
	fmt.Println(list)

	// find
	equals := func(a, b int) bool {
		return a == b
	}
	fmt.Println(list.Find(3, equals))

	// replace
	fmt.Println(list.Replace(10, 3))
	fmt.Println(list)

	// delete
	fmt.Println(list.Delete(5))
	fmt.Println(list)
}
