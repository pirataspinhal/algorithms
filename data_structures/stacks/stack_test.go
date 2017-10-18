package stacks_test

import (
	"testing"

	"github.com/willmadison/algorithms/data_structures/stacks"
)

func TestPushPop(t *testing.T) {
	stack := stacks.NewIntStack()

	for i := 0; i < 5; i++ {
		stack.Push(i)
	}

	last, err := stack.Pop()

	if err != nil {
		t.Fatal("expected stack.Pop() invocation to complete without error:", err)
	}

	if last != 4 {
		t.Fatal("got", last, "expected 4")
	}
}

func TestPeek(t *testing.T) {
	stack := stacks.NewIntStack()

	for i := 0; i < 5; i++ {
		stack.Push(i)
	}

	last, err := stack.Peek()

	if err != nil {
		t.Fatal("expected stack.Peek() invocation to complete without error:", err)
	}

	if last != 4 {
		t.Fatal("got", last, "expected 4")
	}

	last, err = stack.Pop()

	if err != nil {
		t.Fatal("expected stack.Peek() invocation to complete without error:", err)
	}

	if last != 4 {
		t.Fatal("got", last, "expected 4")
	}
}
