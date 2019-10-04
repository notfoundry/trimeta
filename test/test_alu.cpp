//
// Created by Mark on 9/26/2019.
//

#include <dimeta/primitives.hpp>
#include <dimeta/macro/macro.hpp>

#include "alu/alu.hpp"

namespace dmm = dm::macro;
namespace tml = tm::lib;

using alu = dmm::compile<
        alu_8<
                dmm::wire<'X', 0>, dmm::wire<'X', 1>, dmm::wire<'X', 2>, dmm::wire<'X', 3>, dmm::wire<'X', 4>, dmm::wire<'X', 5>, dmm::wire<'X', 6>, dmm::wire<'X', 7>,
                dmm::wire<'Y', 0>, dmm::wire<'Y', 1>, dmm::wire<'Y', 2>, dmm::wire<'Y', 3>, dmm::wire<'Y', 4>, dmm::wire<'Y', 5>, dmm::wire<'Y', 6>, dmm::wire<'Y', 7>,
                dmm::wire<'Z', 'X'>, dmm::wire<'N', 'X'>, dmm::wire<'Z', 'Y'>, dmm::wire<'N', 'Y'>, dmm::wire<'F'>, dmm::wire<'N', 'O'>,

                dmm::wire<'O', 0>, dmm::wire<'O', 1>, dmm::wire<'O', 2>, dmm::wire<'O', 3>, dmm::wire<'O', 4>, dmm::wire<'O', 5>, dmm::wire<'O', 6>, dmm::wire<'O', 7>,
                dmm::wire<'Z', 'R'>, dmm::wire<'N', 'G'>, dmm::wire<'O', 'F'>
        >
>;

using sim = dmm::simulate<
        alu,
        dmm::initial_conditions<
                dmm::state_assignment<dmm::wire<'X', 0>, dm::logic::L>,
                 dmm::state_assignment<dmm::wire<'X', 1>, dm::logic::L>,
                 dmm::state_assignment<dmm::wire<'X', 2>, dm::logic::L>,
                 dmm::state_assignment<dmm::wire<'X', 3>, dm::logic::L>,
                 dmm::state_assignment<dmm::wire<'X', 4>, dm::logic::L>,
                 dmm::state_assignment<dmm::wire<'X', 5>, dm::logic::L>,
                 dmm::state_assignment<dmm::wire<'X', 6>, dm::logic::L>,
                 dmm::state_assignment<dmm::wire<'X', 7>, dm::logic::L>,

                dmm::state_assignment<dmm::wire<'Y', 0>, dm::logic::L>,
                 dmm::state_assignment<dmm::wire<'Y', 1>, dm::logic::L>,
                 dmm::state_assignment<dmm::wire<'Y', 2>, dm::logic::L>,
                 dmm::state_assignment<dmm::wire<'Y', 3>, dm::logic::L>,
                 dmm::state_assignment<dmm::wire<'Y', 4>, dm::logic::L>,
                 dmm::state_assignment<dmm::wire<'Y', 5>, dm::logic::L>,
                 dmm::state_assignment<dmm::wire<'Y', 6>, dm::logic::L>,
                 dmm::state_assignment<dmm::wire<'Y', 7>, dm::logic::L>,

                 dmm::state_assignment<dmm::wire<'Z', 'X'>, dm::logic::H>,
                 dmm::state_assignment<dmm::wire<'N', 'X'>, dm::logic::H>,
                 dmm::state_assignment<dmm::wire<'Z', 'Y'>, dm::logic::H>,
                dmm::state_assignment<dmm::wire<'N', 'Y'>, dm::logic::H>,
                dmm::state_assignment<dmm::wire<'F'>, dm::logic::H>,
                dmm::state_assignment<dmm::wire<'N', 'O'>, dm::logic::H>
        >
>;