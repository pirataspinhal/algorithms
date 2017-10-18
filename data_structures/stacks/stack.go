package stacks

import (
	"errors"
	"fmt"
)

type Stack interface {
	Push(i int)
	Pop() (int, error)
	Peek() (int, error)
}

type intStack struct {
	data []int
	size int
}

func NewIntStack() Stack {
	return &intStack{data: []int{}}
}

func (s *intStack) Push(value int) {
	s.data = append(s.data, value)
	s.size += 1
}

func (s *intStack) Pop() (int, error) {
	if s.size > 0 {
		value := s.data[s.size-1]
		s.size -= 1
		s.data = s.data[:s.size]
		return value, nil
	}

	return 0, errors.New("No Such Element")
}

func (s *intStack) Peek() (int, error) {
	if s.size > 0 {
		value := s.data[s.size-1]
		return value, nil
	}

	return 0, errors.New("No Such Element")
}

func (s *intStack) String() string {
	return fmt.Sprintf("%v", s.data)
}
