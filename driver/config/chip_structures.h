// Copyright 2019 Google LLC
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef DARWINN_DRIVER_CONFIG_CHIP_STRUCTURES_H_
#define DARWINN_DRIVER_CONFIG_CHIP_STRUCTURES_H_

#include "port/integral_types.h"

namespace platforms {
namespace darwinn {
namespace driver {
namespace config {

struct ChipStructures {
  // Hardware required minimum alignment on buffers.
  uint64 minimum_alignment_bytes;

  // Buffer allocation alignment and granularity. Typically this would be same
  // as minimum_alignment_bytes above, however may also factor in other
  // requirements such as host cache line size, cache API constraints etc.
  uint64 allocation_alignment_bytes;

  // Controls AXI burst length.
  uint64 axi_dma_burst_limiter;

  // Number of wire interrupts.
  uint64 num_wire_interrupts;

  // Number of page table entries.
  uint64 num_page_table_entries;

  // Number of physical address bits generated by the hardware.
  uint64 physical_address_bits;

  // Addressable byte size of TPU DRAM (if any). This must be divisible by host
  // table size.
  uint64 tpu_dram_size_bytes;

  // Total size of narrow memory per tile in bytes.
  uint64 narrow_memory_capacity;

  // Size of address translation entry for external narrow memory interface.
  uint64 external_narrow_memory_translate_entry_size_bytes;

  // Number of X tiles.
  uint64 number_x_tiles;

  // Number of Y tiles.
  uint64 number_y_tiles;

  // Number of compute threads.
  uint64 number_compute_threads;

  // Number of virtual networks.
  uint64 number_of_ring_virtual_networks;

  uint64 last_z_out_cell_disable_incompatible_with_sparsity;

  uint64 nlu_buffer_backpressure_causes_assertion;

  // Mesh queue depth.
  uint64 mesh_rx_queue_depth;

  // Default VN buffer size.
  uint64 default_vn_buffer_memory_lines;

  // Base offset for CSR
  uint64 csr_region_base_offset;

  // Size CSR Region
  uint64 csr_region_size_bytes;

  // Support trace architectural registers.
  uint64 support_trace_arch_registers;

  // Shared Memory's base-and-bound unit size in bytes. This value is needed
  // when determining how to program shared memory base and size for parameter,
  // instruction, activation, and scalar memory partitions.
  uint64 base_and_bound_unit_size_bytes;

  // Number of scalar core contexts supported. Default 1 is legacy behavior with
  // no context switching.
  uint64 number_of_scalar_core_contexts;

  uint64 support_tile_thread_gcsr_node;
};

}  // namespace config
}  // namespace driver
}  // namespace darwinn
}  // namespace platforms

#endif  // DARWINN_DRIVER_CONFIG_CHIP_STRUCTURES_H_
