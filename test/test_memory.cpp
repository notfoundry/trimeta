//
// Created by Mark on 9/26/2019.
//

#include <dimeta/primitives.hpp>
#include <dimeta/macro/macro.hpp>

#include <trimeta/memory/ram.hpp>

namespace dmm = dm::macro;

using mod = dmm::compile<
        tm::mem::ram_256<
                dmm::wire<'C'>, dmm::wire<'L'>,
                dmm::wire<'D', 0>, dmm::wire<'D', 1>, dmm::wire<'D', 2>, dmm::wire<'D', 3>, dmm::wire<'D', 4>, dmm::wire<'D', 5>, dmm::wire<'D', 6>, dmm::wire<'D', 7>,
                dmm::wire<'A', 0>, dmm::wire<'A', 1>, dmm::wire<'A', 2>, dmm::wire<'A', 3>, dmm::wire<'A', 4>, dmm::wire<'A', 5>, dmm::wire<'A', 6>, dmm::wire<'A', 7>,
                dmm::wire<'O', 0>, dmm::wire<'O', 1>, dmm::wire<'O', 2>, dmm::wire<'O', 3>, dmm::wire<'O', 4>, dmm::wire<'O', 5>, dmm::wire<'O', 6>, dmm::wire<'O', 7>
        >
>;

