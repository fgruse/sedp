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
    float      energy;  // energy carrying

    // ToDo: forward declare here
    void* operator new(std::size_t size) noexcept;
    void operator delete(void* ptr) noexcept;
};

struct MemoryPool {
    std::size_t initial;
    uint8_t buf[32*10000];
    bool freeList[10000];
public:
    explicit MemoryPool(std::size_t initial = 10000);
    ~MemoryPool();
    void* addToPool(std::size_t sz);
    void deleteFromPool(void* ptr);
    //Particle& operator[](size_t n);
    //Particle operator[](size_t n) const;
};
