package main

import (
	"fmt"
	"os/user"
	"time"
)

func main() {
	fmt.Println("Hello, world\n", time.Now())
	fmt.Println(user.Current())
}
