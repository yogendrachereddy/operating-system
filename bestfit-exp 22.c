#include <stdio.h>
#define MEMORY_SIZE 1000

// Structure to represent a block of memory
struct MemoryBlock {
    int id;       // Process ID
    int size;     // Size of the memory block
    int allocated; // Flag indicating whether the block is allocated or not
};

// Function to initialize the memory blocks
void initializeMemory(struct MemoryBlock memory[], int numBlocks) {
    for (int i = 0; i < numBlocks; i++) {
        memory[i].id = -1;
        memory[i].size = 0;
        memory[i].allocated = 0;
    }
}

// Function to display the state of memory
void displayMemory(struct MemoryBlock memory[], int numBlocks) {
    printf("Memory State:\n");
    for (int i = 0; i < numBlocks; i++) {
        printf("[%d] Size: %d, Allocated: %s\n", i, memory[i].size,
               memory[i].allocated ? "Yes" : "No");
    }
    printf("\n");
}

// Function to allocate memory using the best-fit algorithm
void bestFit(struct MemoryBlock memory[], int numBlocks, int processId, int processSize) {
    int bestFitIndex = -1;
    int bestFitSize = MEMORY_SIZE + 1;

    // Find the smallest available block that is large enough
    for (int i = 0; i < numBlocks; i++) {
        if (!memory[i].allocated && memory[i].size >= processSize) {
            if (memory[i].size < bestFitSize) {
                bestFitIndex = i;
                bestFitSize = memory[i].size;
            }
        }
    }

    // Allocate memory if a suitable block is found
    if (bestFitIndex != -1) {
        memory[bestFitIndex].id = processId;
        memory[bestFitIndex].allocated = 1;
        printf("Process %d allocated to block %d\n", processId, bestFitIndex);
    } else {
        printf("Process %d cannot be allocated\n", processId);
    }
}

// Function to deallocate memory
void deallocateMemory(struct MemoryBlock memory[], int numBlocks, int processId) {
    for (int i = 0; i < numBlocks; i++) {
        if (memory[i].id == processId) {
            memory[i].id = -1;
            memory[i].allocated = 0;
            printf("Memory block %d deallocated\n", i);
            return;
        }
    }
    printf("Process %d not found in memory\n", processId);
}

int main() {
    // Number of memory blocks
    int numBlocks = 5;

    // Define an array of memory blocks
    struct MemoryBlock memory[MEMORY_SIZE];

    // Initialize memory
    initializeMemory(memory, numBlocks);

    // Display initial state of memory
    displayMemory(memory, numBlocks);

    // Allocate memory using best-fit algorithm
    bestFit(memory, numBlocks, 1, 200);
    bestFit(memory, numBlocks, 2, 300);
    bestFit(memory, numBlocks, 3, 150);
    bestFit(memory, numBlocks, 4, 400);

    // Display state of memory after allocations
    displayMemory(memory, numBlocks);

    // Deallocate memory
    deallocateMemory(memory, numBlocks, 2);

    // Display state of memory after deallocation
    displayMemory(memory, numBlocks);

    return 0;
}
