//
// Created by Mark on 9/19/2019.
//

#include <dimeta/macro/primitives.hpp>
#include <dimeta/macro/compiler.hpp>
#include <dimeta/macro/simulator.hpp>

#include <trimeta/unit_primitives.hpp>
#include <trimeta/clock.hpp>

namespace dmm = dm::macro;
namespace tml = tm::lib;

template <class R, class S, class Q, class Q_>
using sr_latch = dmm::assembly<
        dmm::in<R, S>,
        dmm::out<Q, Q_>,
        tml::unit_nor2<R*, Q_*, Q*>,
        tml::unit_nor2<S*, Q*, Q_*>
>;

template <class D, class C, class Q, class QNot>
using posedge_ms_d_flipflop = dmm::assembly<
        dmm::in<D, C>,
        dmm::out<Q, QNot>,

        tml::unit_not<C*, dmm::wire<0>>,

        tml::unit_nand2<D*, dmm::wire<0>, dmm::wire<1>>,
        tml::unit_nand2<dmm::wire<0>, dmm::wire<1>, dmm::wire<2>>,
        tml::unit_not<dmm::wire<0>, dmm::wire<3>>,

        sr_latch<dmm::wire<1>, dmm::wire<2>, dmm::wire<4>, dmm::wire<'Q',0>>,

        tml::unit_nand2<dmm::wire<4>, dmm::wire<3>, dmm::wire<5>>,
        tml::unit_nand2<dmm::wire<5>, dmm::wire<3>, dmm::wire<6>>,

        sr_latch<dmm::wire<5>, dmm::wire<6>, Q*, QNot*>
>;


template <class A, class B, class C, class O>
using and3 = dmm::assembly<
        dmm::in<A, B, C>,
        dmm::out<O>,
        tml::unit_and2<A*, B*, dmm::wire<0>>,
        tml::unit_and2<C*, dmm::wire<0>, O*>
>;

template <class A, class B, class C, class D, class O>
using or4 = dmm::assembly<
        dmm::in<A, B, C, D>,
        dmm::out<O>,
        tml::unit_or2<A*, B*, dmm::wire<0>>,
        tml::unit_or2<C*, D*, dmm::wire<1>>,
        tml::unit_or2<dmm::wire<0>, dmm::wire<1>, O*>
>;

template <class S0, class S1, class I0, class I1, class I2, class I3, class O>
using mux_4_to_1 = dmm::assembly<
        dmm::in<S0, S1, I0, I1, I2, I3>,
        dmm::out<O>,

        tml::unit_not<S0*, dmm::wire<0>>,
        tml::unit_not<S1*, dmm::wire<1>>,

        and3<dmm::wire<0>, dmm::wire<1>, I0*, dmm::wire<2>>,
        and3<dmm::wire<0>, S1*, I1*, dmm::wire<3>>,
        and3<S0*, dmm::wire<1>, I2*, dmm::wire<4>>,
        and3<S0*, S1*, I3*, dmm::wire<5>>,

        or4<dmm::wire<2>, dmm::wire<3>, dmm::wire<4>, dmm::wire<5>, O*>
>;

using comp = dmm::compile<tml::ring_oscillator<dmm::wire<'I'>, dmm::wire<'O'>, 1>>;

using sim = dmm::simulate<
        comp,
        dmm::initial_conditions<
                dmm::state_assignment<dmm::wire<'I'>, dm::logic::H>
        >
>;

int main() {}