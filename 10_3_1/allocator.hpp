#ifndef ALLOCATOR_HPP
#define ALLOCATOR_HPP
#include <cstddef>
#include <iostream>
#include <limits>
#include <new>
template <typename T, std::size_t Mem_ByteSize>
class allocator
{
  public:
    using value_type = T;
    using alloc_storage_type = uint8_t *;

    allocator() noexcept = default;

    template <typename U>
    struct rebind
    {
        using other = allocator<U, Mem_ByteSize>;
    };

    constexpr T *allocate(size_t n) noexcept
    {
        if (current_index + n > max_size())
        {
            return nullptr;
        }

        void *raw_memory = &_mem_pool[current_index];
        current_index += n * sizeof(T);

        T *allocated_ptr = new (raw_memory) T[n]; // Placement new ..? i think

        return allocated_ptr;
    }
    constexpr void deallocate(T *p, std::size_t n) noexcept
    {
    }
    constexpr std::size_t max_size() const noexcept
    {
        return std::numeric_limits<std::size_t>::max() / sizeof(T);
    }

  private:
    static uint8_t _mem_pool[Mem_ByteSize];
    std::size_t current_index = 0;
};
template <typename T, std::size_t Mem_ByteSize>
uint8_t allocator<T, Mem_ByteSize>::_mem_pool[Mem_ByteSize];

#endif