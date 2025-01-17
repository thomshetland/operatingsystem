#ifndef GDT_H
#define GDT_H

#include <libc/stdint.h>

extern void gdt_flush();

// Structure representing a Global Descriptor Table (GDT) entry
struct gdt_entry_struct{
    uint16_t limit_low; // Segment limit
    uint16_t base_low; // Lower 16 bits of the base address
    uint8_t base_middle; // Next 8 bits of the base address
    uint8_t access; // Access flags
    uint8_t flags; // Flags (granualarity, size)
    uint8_t base_high; // Upper 8 bots of the base address
}__attribute__((packed)); // Ensure packed without padding


// Structure representing the GDT pointer
struct gdt_ptr_struct{
    uint16_t limit; // Size in bytes - 1
    unsigned int base; // Base address
}__attribute__((packed)); // Ensure packed without padding

// Declare the function to initialize the GDT
void init_gdt();

// Load the gdt
void gdt_load(struct gdt_ptr_struct *_gdtp);

// Declare the function to set up a GDT gate
void set_gdt_gate(uint32_t num, uint32_t base, uint32_t limit, uint8_t access, uint8_t flag);

#endif // GDT_H