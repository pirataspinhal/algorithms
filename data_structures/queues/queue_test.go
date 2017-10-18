package queues_test

import (
	"testing"

	"github.com/willmadison/algorithms/data_structures/queues"
)

func TestEnqueueDequeue(t *testing.T) {
	queue := queues.NewIntQueue()

	for i := 0; i < 5; i++ {
		queue.Enqueue(i)
	}

	first, err := queue.Dequeue()

	if err != nil {
		t.Fatal("expected queue.Dequeue() invocation to complete without error:", err)
	}

	if first != 0 {
		t.Fatal("got", first, "expected 0")
	}
}
