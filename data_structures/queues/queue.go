package queues

import (
	"errors"
	"fmt"
)

type Queue interface {
	Enqueue(i int)
	Dequeue() (int, error)
	Peek() (int, error)
}

type intQueue struct {
	data []int
	size int
}

func NewIntQueue() Queue {
	return &intQueue{data: []int{}}
}

func (s *intQueue) Enqueue(value int) {
	s.data = append(s.data, value)
	s.size += 1
}

func (s *intQueue) Dequeue() (int, error) {
	if s.size > 0 {
		value := s.data[0]
		s.size -= 1
		s.data = s.data[1:]

		return value, nil
	}

	return 0, errors.New("No Such Element")
}

func (s *intQueue) Peek() (int, error) {
	if s.size > 0 {
		value := s.data[0]
		return value, nil
	}

	return 0, errors.New("No Such Element")
}

func (s *intQueue) String() string {
	return fmt.Sprintf("%v", s.data)
}
