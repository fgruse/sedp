#pragma once

#include <chrono>

#include <QtGui/QVector2D>
#include <QtCore/qmath.h>


// There are cells and particles: each cell is initialized
// with a certain quota of energy of the overall energy g_energy.
// When a cell has a high energy level, it is more likeley to
// spawn particles and thereby randomly distributing its own energy
// to the particles...
// The particles get a random life time (tod), random position
// within the cell, a random velocity as well as the random energy
// quota from the cell.
// The particle then moves until time of death (tod) is reached.
// The particle then passes its energy quota back to its underlying
// cell. Theryby cells are reloaded again and again and a cylce is
// closed, causing continuous particle spawning...


using time_point = std::chrono::high_resolution_clock::time_point;
using secs = std::chrono::duration<float, std::chrono::seconds::period>;

struct MemoryPool;

struct Particle
{
    static MemoryPool pool;
    QVector2D  position;
    QVector2D  velocity;
    time_point tod;     // time of death
    float      energy{};  // energy carrying

    void* operator new(std::size_t size) noexcept;
    void operator delete(void* ptr) noexcept;
};

struct MemoryPool {
    static const long bufferSize = static_cast<const long>(1572999999.9999673); // ca. 1.5MiB
    static const int freeListSize = bufferSize / sizeof(Particle);
    char buf[bufferSize]{};
    bool freeList[freeListSize]{};
public:
    explicit MemoryPool() noexcept;
    ~MemoryPool();
    void* addToPool(std::size_t sz);
    void deleteFromPool(void* ptr);
};

