//
// Created by Mark on 9/26/2019.
//

#include <dimeta/primitives.hpp>
#include <dimeta/macro/macro.hpp>

#include <trimeta/alu/adder.hpp>

namespace dmm = dm::macro;

struct test_all_zero {
    using mod = dmm::compile<
            tm::alu::rc_adder_2<
                    dmm::wire<'C', 'i', 'n'>,
                    dmm::wire<'A', 0>, dmm::wire<'A', 1>,
                    dmm::wire<'B', 0>, dmm::wire<'B', 1>,
                    dmm::wire<'S', 0>, dmm::wire<'S', 1>,
                    dmm::wire<'C', 'o', 'u', 't'>
            >
    >;

    using sim = dmm::simulate<
            mod,
            dmm::initial_conditions<
                    dmm::state_assignment<dmm::wire<'C', 'i', 'n'>, dm::logic::L>,
                    dmm::state_assignment<dmm::wire<'A', 0>, dm::logic::L>,
                    dmm::state_assignment<dmm::wire<'A', 1>, dm::logic::L>,
                    dmm::state_assignment<dmm::wire<'B', 0>, dm::logic::L>,
                    dmm::state_assignment<dmm::wire<'B', 1>, dm::logic::L>
            >
    >;

    static_assert(sim::template probe<dmm::wire<'S', 0>>::output::value == dm::logic::L);
    static_assert(sim::template probe<dmm::wire<'S', 1>>::output::value == dm::logic::L);
    static_assert(sim::template probe<dmm::wire<'C', 'o', 'u', 't'>>::output::value == dm::logic::L);
};

struct test_all_one {
    using mod = dmm::compile<
            tm::alu::rc_adder_2<
                    dmm::wire<'C', 'i', 'n'>,
                    dmm::wire<'A', 0>, dmm::wire<'A', 1>,
                    dmm::wire<'B', 0>, dmm::wire<'B', 1>,
                    dmm::wire<'S', 0>, dmm::wire<'S', 1>,
                    dmm::wire<'C', 'o', 'u', 't'>
            >
    >;

    using sim = dmm::simulate<
            mod,
            dmm::initial_conditions<
                    dmm::state_assignment<dmm::wire<'C', 'i', 'n'>, dm::logic::H>,
                    dmm::state_assignment<dmm::wire<'A', 0>, dm::logic::H>,
                    dmm::state_assignment<dmm::wire<'A', 1>, dm::logic::H>,
                    dmm::state_assignment<dmm::wire<'B', 0>, dm::logic::H>,
                    dmm::state_assignment<dmm::wire<'B', 1>, dm::logic::H>
            >
    >;

    static_assert(sim::template probe<dmm::wire<'S', 0>>::output::value == dm::logic::H);
    static_assert(sim::template probe<dmm::wire<'S', 1>>::output::value == dm::logic::H);
    static_assert(sim::template probe<dmm::wire<'C', 'o', 'u', 't'>>::output::value == dm::logic::H);
};