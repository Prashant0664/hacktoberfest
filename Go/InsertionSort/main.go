package main

import "fmt"

func insertionSort(arr []int)  {
	for i:=0; i<len(arr); i++ {
		var key= arr[i]
		var j=i-1
		
		for j>=0 && key < arr[j] {
			arr[j + 1] = arr[j]
                j -= 1
		}
		arr[j + 1] = key
	}
}

func main() {
	arr:= []int{12, 13, 11, 5, 6}
	insertionSort(arr)
	fmt.Println(arr)
	
=======
package main

import "fmt"

func insertionSort(arr []int)  {
	for i:=0; i<len(arr); i++ {
		var key= arr[i]
		var j=i-1
		
		for j>=0 && key < arr[j] {
			arr[j + 1] = arr[j]
                j -= 1
		}
		arr[j + 1] = key
	}
}

func main() {
	arr:= []int{12, 13, 11, 5, 6}
	insertionSort(arr)
	fmt.Println(arr)
	
}