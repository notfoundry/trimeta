//
// Created by Mark on 10/4/2019.
//

#ifndef TRIMETA_DFF_HPP
#define TRIMETA_DFF_HPP

#include <dimeta/macro/macro.hpp>
#include <trimeta/unit_primitives.hpp>

namespace tm::mem {
    namespace dmm = dm::macro;

    template <class R, class S, class Q, class Q_>
    using sr_latch = dmm::assembly<
            dmm::in<R, S>,
            dmm::out<Q, Q_>,
            unit_nor2<R*, Q_*, Q*>,
            unit_nor2<S*, Q*, Q_*>
    >;

    template <class C, class D, class Q, class QNot>
    using posedge_ms_d_flipflop = dmm::assembly<
            dmm::in<C, D>,
            dmm::out<Q, QNot>,

            unit_not<C*, dmm::wire<0>>,

            unit_nand2<D*, dmm::wire<0>, dmm::wire<1>>,
            unit_nand2<dmm::wire<0>, dmm::wire<1>, dmm::wire<2>>,
            unit_not<dmm::wire<0>, dmm::wire<3>>,

            sr_latch<dmm::wire<1>, dmm::wire<2>, dmm::wire<4>, dmm::wire<'Q',0>>,

            unit_nand2<dmm::wire<4>, dmm::wire<3>, dmm::wire<5>>,
            unit_nand2<dmm::wire<5>, dmm::wire<3>, dmm::wire<6>>,

            sr_latch<dmm::wire<5>, dmm::wire<6>, Q*, QNot*>
    >;
}

#endif //TRIMETA_DFF_HPP
