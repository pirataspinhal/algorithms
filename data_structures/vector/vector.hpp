#pragma once

#include <memory>
#include <iterator>
#include <utility>
#include <cstddef>

namespace ds {

template <typename T, typename Alloc = std::allocator<T>>
class vector {
    using alloc_traits = std::allocator_traits<Alloc>;

 public:
    // Aliases
    using value_type = T;
    using allocator_type = Alloc;
    using size_type = typename alloc_traits::size_type;
    using difference_type = typename alloc_traits::difference_type;
    using reference = value_type&;
    using const_reference = const value_type&;
    using pointer = typename alloc_traits::pointer;
    using const_pointer = typename alloc_traits::const_pointer;
    using iterator = value_type*;
    using const_iterator = const value_type*;
    using reverse_iterator = std::reverse_iterator<iterator>;
    using const_reverse_iterator = std::reverse_iterator<const_iterator>;

    // Constructors
    explicit vector(const allocator_type& alloc = allocator_type{})
	: m_alloc{alloc}, m_data{nullptr}, m_size{0}, m_capacity{0} {}

    // Iterators
    constexpr iterator begin() noexcept { return &m_data[0]; }
    constexpr const_iterator cbegin() noexcept { return &m_data[0]; }
    constexpr const_iterator begin() const noexcept { return &m_data[0]; }
    constexpr iterator end() noexcept { return &m_data[m_size]; }
    constexpr const_iterator cend() noexcept { return &m_data[m_size]; }
    constexpr const_iterator end() const noexcept { return &m_data[m_size]; }
    constexpr reverse_iterator rbegin() noexcept { return &m_data[m_size]; }
    constexpr const_reverse_iterator crbegin() noexcept { return &m_data[m_size]; }
    constexpr const_reverse_iterator rbegin() const noexcept { return &m_data[m_size]; }
    constexpr reverse_iterator rend() noexcept { return &m_data[0]; }
    constexpr const_reverse_iterator crend() noexcept { return &m_data[0]; }
    constexpr const_reverse_iterator rend() const noexcept { return &m_data[0]; }

    // Element access
    constexpr value_type& operator[](size_type i) { return data()[i]; }
    constexpr const value_type& operator[](size_type i) const { return data()[i]; }

    constexpr value_type* data() noexcept { return static_cast<value_type*>(m_data); }
    constexpr const value_type* data() const noexcept { return static_cast<value_type*>(m_data); }

    // Modifiers
    void push_back(const value_type& value) { emplace_back(value); }
    void push_back(value_type&& value) { emplace_back(std::move(value)); }

    template <typename ...Args>
    value_type& emplace_back(Args&&... args) {
	if (m_size == m_capacity) {
	    m_capacity = (m_capacity + 1) * 2;

	    pointer new_data = alloc_traits::allocate(m_alloc, m_capacity);
	    iterator first = begin();
	    const_iterator last = cend();
	    pointer dest = new_data;

	    for (; first != last; ++dest, ++first) {
		alloc_traits::construct(m_alloc, dest, std::forward<Args>(args)...);
		alloc_traits::destroy(m_alloc, first);
	    }

	    alloc_traits::deallocate(m_alloc, m_data, m_size);
	    m_data = new_data;
	}

	alloc_traits::construct(m_alloc, &m_data[m_size], std::forward<Args>(args)...);

	return m_data[++m_size];
    }

    // Capacity
    constexpr size_type size() const noexcept { return m_size; }
    constexpr size_type capacity() const noexcept { return m_capacity; }
    constexpr bool empty() const noexcept { return m_size == 0; }
    constexpr size_type max_size() const noexcept { return alloc_traits::max_size(m_alloc); }

 private:
    allocator_type m_alloc;
    pointer m_data;
    size_type m_size;
    size_type m_capacity;
};

} // namespace ds
