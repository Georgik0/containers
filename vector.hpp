#ifndef VECTOR_HPP
#define VECTOR_HPP

#include "vector_iterator.hpp"
#include "reverse_iterator.hpp"
#include <memory>
#include <iostream>
#include <vector>

namespace   ft {

    template < class Type, class Alloc = std::allocator<Type> >
    class vector {
    public:
        typedef Type                                                            value_type;
        typedef Alloc                                                           allocator_type;
        
        typedef std::size_t                                                     size_type;
        typedef std::ptrdiff_t                                                  difference_type;
        
        typedef value_type&                                                     reference;
        typedef const value_type&                                               const_reference;
        
        typedef typename allocator_type::pointer                                pointer;
        typedef typename allocator_type::const_pointer                          const_pointer;

        typedef typename ft::vector_iterator<Type, Type*, Type&>                iterator;
        typedef typename ft::vector_iterator<Type, const Type*, const Type&>    const_iterator;
        typedef typename ft::reverse_iterator<iterator>                         reverse_iterator;
        typedef typename ft::reverse_iterator<const_iterator>                   const_reverse_iterator;
    private:
        allocator_type  _alloc;
        pointer         _ptr;
        size_type       _cap;
        size_type       _len;

        void increase_cap(size_type count) {
            while (_len + count > _cap)
                _cap *= 2;
        }
    public:
        explicit vector(const allocator_type &alloc = allocator_type()) : _alloc(alloc), _len(0), _cap(0), _ptr(0) {}

        explicit vector(size_type n, const value_type &val = value_type(), const allocator_type &alloc = allocator_type()) :
         _alloc(alloc), _ptr(0), _len(n), _cap(n) {
            _ptr = _alloc.allocate(n);
            for (size_t i = 0; i < n; i++) {
                _alloc.construct(_ptr + i, val);
            }
        }

        template <class InputIt>
        vector(InputIt first, InputIt last,
         const allocator_type &alloc = allocator_type(),
         typename std::enable_if<!std::is_integral<InputIt>::value>::type* = 0) :
         _alloc(alloc), _ptr(0), _len(0), _cap(0)  {
            InputIt value = first;
            _len = last - first;
            if (first > last) {
                _len = -_len;
                value = last;
            }
            _cap = _len;
            _ptr = _alloc.allocate(_cap);
            for (size_type i = 0; i < _len; i++) {
                _alloc.construct(_ptr + i, *(value + i));
            }
        }

        vector(const vector &v) : _alloc(v._alloc), _ptr(0), _len(v._len), _cap(v._cap) {
            _ptr = _alloc.allocate(_cap);
            for (size_type i = 0; i < _len; i++) {
                _alloc.construct(_ptr + i, v[i]);
            }
        }

        ~vector() {
            clear();
            _alloc.deallocate(_ptr, _cap);
            _ptr = NULL;
        };

        vector &operator=(const vector &v) {
            if (this == &v)
                return (*this);
            this->~vector();
            _cap = v._cap;
            _len = v._len;
            _ptr = _alloc.allocate(_cap);
            for (size_type i = 0; i < _len; i++) {
                _alloc.construct(_ptr + i, v[i]);
            }
        }

        // ------------------- Element access ------------------- //
        reference at(size_type pos) {
            if (pos >= _len)
                throw std::out_of_range("Out of range");
            return *(_ptr + pos);
        }

        const_reference at (size_type pos) const {
            if (pos >= _len)
                throw std::out_of_range("Out of range");
            return *(_ptr + pos);
        }

        reference   operator[](size_type pos) { return *(_ptr + pos); }
        const_reference operator[](size_type pos) const { return *(_ptr + pos); }

        reference   front() { return *_ptr; }
        const_reference   front() const { return *_ptr; }

        reference   back() { return *(_ptr + _len - 1); }
        const_reference   back() const { return *(_ptr + _len - 1); }

        pointer data() { return _ptr; }
        const_pointer data() const { return _ptr; }


        // ------------------- Iterators ------------------- //
        iterator    begin() { return iterator(_ptr); }
        iterator    end() { return iterator(_ptr + _len); }

        const_iterator  begin() const { return const_iterator(_ptr); }
        const_iterator  end() const { return const_iterator(_ptr + _len); }

        reverse_iterator    rbegin() { return reverse_iterator(end()); }
        reverse_iterator    rend() { return reverse_iterator(begin()); }

        const_reverse_iterator  rbegin() const { return const_reverse_iterator(end()); }
        const_reverse_iterator  rend() const { return const_reverse_iterator(begin()); }

        // ------------------- Capacity ------------------- //
        bool    empty() const { return _len == 0; }
        size_type   size() const { return _len; }
        size_type   max_size() const { return _alloc.max_size(); }

        void    reserve(size_type new_cap) {
            if (new_cap <= _cap)
                return;
            pointer ptr_new = _alloc.allocate(new_cap);
            for (size_t i = 0; i < _len; i++) {
                _alloc.construct(ptr_new + i, _ptr[i]);
            }
            size_type len_tmp = _len;
            clear();
            _alloc.deallocate(_ptr, _cap);
            _len = len_tmp;
            _cap = new_cap;
            _ptr = ptr_new;
        }

        size_type   capacity() const { return _cap; }

        // ------------------- Modifiers ------------------- //
        void    clear() {
            for (size_type i = 0; i < _len; i++) {
                if (_ptr + i)
                    _alloc.destroy(_ptr + i);
            }
            _len = 0;
        }

        void    push_back(const_reference value) {
            if (_len >= _cap) {
                reserve(_cap * 2 + (_cap == 0));
            }
            // std::cout << "\ntest bushback\n" << "_len = " << _len << "\n_cap = " << _cap << "\n";
            _alloc.construct(_ptr + _len, value);
            _len++;
        }

        iterator    insert(iterator pos, const_reference value) {
            insert(pos, 1, value);
            return pos;
        }

        void    insert(iterator pos, size_type count, const_reference value) {
            size_type   id = pos - begin();

            if (_len + count > _cap) {
                increase_cap(count);

                pointer ptr_new = _alloc.allocate(_cap);

                for (size_t i = 0; i < id; i++) {
                    _alloc.construct(ptr_new + i, _ptr[i]);
                }
                for (size_t i = 0; i < count; i++) {
                    _alloc.construct(ptr_new + id + i, value);
                }
                for (size_t i = id + count, j = id; i < _len + count; i++, j++) {
                    _alloc.construct(ptr_new + i, _ptr[j]);
                }
                clear();
                _alloc.deallocate(_ptr, _cap);
                _ptr = ptr_new;
            } else {
                for (size_t i = _len - 1; i >= id; i--) {
                    _alloc.construct(_ptr + i + count, _ptr[i]);
                }
                for (size_t i = 0; i < count; i++) {
                    _alloc.construct(_ptr + id + i, value);
                }
            }
            _len += count;
        }

        template< class InputIt >
        void    insert(iterator pos, InputIt first, InputIt last) {
            size_type   count = last - first;
            size_type   id = pos - begin();

            if (_len + count > _cap) {
                increase_cap(count);

                pointer ptr_new = _alloc.allocate(_cap);

                for (size_t i = 0; i < id; i++) {
                    _alloc.construct(ptr_new + i, _ptr[i]);
                }
                for (size_t i = 0; i < count; i++) {
                    _alloc.construct(ptr_new + id + i, *(first + i));
                }
                for (size_t i = id + count, j = id; i < _len + count; i++, j++) {
                    _alloc.construct(ptr_new + i, _ptr[j]);
                }
                clear();
                _alloc.deallocate(_ptr, _cap);
                _ptr = ptr_new;
            } else {
                for (size_t i = _len - 1; i >= id; i--) {
                    _alloc.construct(_ptr + i + count, _ptr[i]);
                }
                for (size_t i = 0; i < count; i++) {
                    _alloc.construct(_ptr + id + i, *(first + i));
                }
            }
            _len += count;
        }

    };
}

#endif //VECTOR_HPP