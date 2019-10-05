//
// Created by Mark on 9/26/2019.
//

#ifndef TRIMETA_MUX_HPP
#define TRIMETA_MUX_HPP

#include <dimeta/macro/macro.hpp>
#include <trimeta/unit_primitives.hpp>

#include <trimeta/lib/or.hpp>
#include <trimeta/lib/decoder.hpp>

namespace tm::lib {
    namespace dmm = dm::macro;

    template <
            class I0, class I1,
            class S0,
            class O
    >
    using mux_2_1 = dmm::assembly<
            dmm::in<I0, I1, S0>,
            dmm::out<O>,

            unit_not<S0*, dmm::wire<0>>,
            unit_and2<I0*, dmm::wire<0>, dmm::wire<1>>,
            unit_and2<I1*, S0*, dmm::wire<2>>,
            unit_or2<dmm::wire<1>, dmm::wire<2>, O*>
    >;

    template <
            class I0, class I1, class I2, class I3,
            class S0, class S1,
            class O
    >
    using mux_4_1 = dmm::assembly<
            dmm::in<I0, I1, I2, I3, S0, S1>,
            dmm::out<O>,

            decoder_2_4<S0*, S1*, dmm::wire<'D', 0>, dmm::wire<'D', 1>, dmm::wire<'D', 2>, dmm::wire<'D', 3>>,
            unit_and2<I0*, dmm::wire<'D', 0>, dmm::wire<'O', 0>>,
            unit_and2<I1*, dmm::wire<'D', 1>, dmm::wire<'O', 1>>,
            unit_and2<I2*, dmm::wire<'D', 2>, dmm::wire<'O', 2>>,
            unit_and2<I3*, dmm::wire<'D', 3>, dmm::wire<'O', 3>>,
            or_4_1<dmm::wire<'O', 0>, dmm::wire<'O', 1>, dmm::wire<'O', 2>, dmm::wire<'O', 3>, O*>
    >;

    template <
            class I0, class I1, class I2, class I3, class I4, class I5, class I6, class I7,
            class S0, class S1, class S2,
            class O
    >
    using mux_8_1 = dmm::assembly<
            dmm::in<I0, I1, I2, I3, I4, I5, I6, I7, S0, S1, S2>,
            dmm::out<O>,

            mux_4_1<I0*, I1*, I2*, I3*, S0*, S1*, dmm::wire<0>>,
            mux_4_1<I4*, I5*, I6*, I7*, S0*, S1*, dmm::wire<1>>,
            mux_2_1<dmm::wire<0>, dmm::wire<1>, S2*, O*>
    >;

    template <
            class I0, class I1, class I2, class I3, class I4, class I5, class I6, class I7,
            class I8, class I9, class I10, class I11, class I12, class I13, class I14, class I15,
            class S0, class S1, class S2, class S3,
            class O
    >
    using mux_16_1 = dmm::assembly<
            dmm::in<I0, I1, I2, I3, I4, I5, I6, I7, I8, I9, I10, I11, I12, I13, I14, I15, S0, S1, S2, S3>,
            dmm::out<O>,

            mux_8_1<
                    I0*, I1*, I2*, I3*, I4*, I5*, I6*, I7*,
                    S0*, S1*, S2*, dmm::wire<0>>,
            mux_8_1<
                    I8*, I9*, I10*, I11*, I12*, I13*, I14*, I15*,
                    S0*, S1*, S2*, dmm::wire<1>>,
            mux_2_1<dmm::wire<0>, dmm::wire<1>, S3*, O*>
    >;

    template <
            class I0, class I1, class I2, class I3, class I4, class I5, class I6, class I7,
            class I8, class I9, class I10, class I11, class I12, class I13, class I14, class I15,
            class I16, class I17, class I18, class I19, class I20, class I21, class I22, class I23,
            class I24, class I25, class I26, class I27, class I28, class I29, class I30, class I31,
            class S0, class S1, class S2, class S3, class S4,
            class O
    >
    using mux_32_1 = dmm::assembly<
            dmm::in<
                    I0, I1, I2, I3, I4, I5, I6, I7, I8, I9, I10, I11, I12, I13, I14, I15,
                    I16, I17, I18, I19, I20, I21, I22, I23, I24, I25, I26, I27, I28, I29, I30, I31,
                    S0, S1, S2, S3, S4
            >,
            dmm::out<O>,

            mux_16_1<
                    I0*, I1*, I2*, I3*, I4*, I5*, I6*, I7*, I8*, I9*, I10*, I11*, I12*, I13*, I14*, I15*,
                    S0*, S1*, S2*, S3*, dmm::wire<0>>,
            mux_16_1<
                    I16*, I17*, I18*, I19*, I20*, I21*, I22*, I23*, I24*, I25*, I26*, I27*, I28*, I29*, I30*, I31*,
                    S0*, S1*, S2*, S3*, dmm::wire<1>>,
            mux_2_1<dmm::wire<0>, dmm::wire<1>, S4*, O*>
    >;

    template <
            class I0, class I1, class I2, class I3, class I4, class I5, class I6, class I7,
            class I8, class I9, class I10, class I11, class I12, class I13, class I14, class I15,
            class I16, class I17, class I18, class I19, class I20, class I21, class I22, class I23,
            class I24, class I25, class I26, class I27, class I28, class I29, class I30, class I31,
            class I32, class I33, class I34, class I35, class I36, class I37, class I38, class I39,
            class I40, class I41, class I42, class I43, class I44, class I45, class I46, class I47,
            class I48, class I49, class I50, class I51, class I52, class I53, class I54, class I55,
            class I56, class I57, class I58, class I59, class I60, class I61, class I62, class I63,
            class S0, class S1, class S2, class S3, class S4, class S5,
            class O
    >
    using mux_64_1 = dmm::assembly<
            dmm::in<
                    I0, I1, I2, I3, I4, I5, I6, I7, I8, I9, I10, I11, I12, I13, I14, I15,
                    I16, I17, I18, I19, I20, I21, I22, I23, I24, I25, I26, I27, I28, I29, I30, I31,
                    I32, I33, I34, I35, I36, I37, I38, I39, I40, I41, I42, I43, I44, I45, I46, I47,
                    I48, I49, I50, I51, I52, I53, I54, I55, I56, I57, I58, I59, I60, I61, I62, I63,
                    S0, S1, S2, S3, S4, S5
            >,
            dmm::out<O>,

            mux_32_1<
                    I0*, I1*, I2*, I3*, I4*, I5*, I6*, I7*, I8*, I9*, I10*, I11*, I12*, I13*, I14*, I15*,
                    I16*, I17*, I18*, I19*, I20*, I21*, I22*, I23*, I24*, I25*, I26*, I27*, I28*, I29*, I30*, I31*,
                    S0*, S1*, S2*, S3*, S4*, dmm::wire<0>>,
            mux_32_1<
                    I32*, I33*, I34*, I35*, I36*, I37*, I38*, I39*, I40*, I41*, I42*, I43*, I44*, I45*, I46*, I47*,
                    I48*, I49*, I50*, I51*, I52*, I53*, I54*, I55*, I56*, I57*, I58*, I59*, I60*, I61*, I62*, I63*,
                    S0*, S1*, S2*, S3*, S4*, dmm::wire<1>>,
            mux_2_1<dmm::wire<0>, dmm::wire<1>, S5*, O*>
    >;

    template <
            class I0, class I1, class I2, class I3, class I4, class I5, class I6, class I7,
            class I8, class I9, class I10, class I11, class I12, class I13, class I14, class I15,
            class I16, class I17, class I18, class I19, class I20, class I21, class I22, class I23,
            class I24, class I25, class I26, class I27, class I28, class I29, class I30, class I31,
            class I32, class I33, class I34, class I35, class I36, class I37, class I38, class I39,
            class I40, class I41, class I42, class I43, class I44, class I45, class I46, class I47,
            class I48, class I49, class I50, class I51, class I52, class I53, class I54, class I55,
            class I56, class I57, class I58, class I59, class I60, class I61, class I62, class I63,
            class I64, class I65, class I66, class I67, class I68, class I69, class I70, class I71,
            class I72, class I73, class I74, class I75, class I76, class I77, class I78, class I79,
            class I80, class I81, class I82, class I83, class I84, class I85, class I86, class I87,
            class I88, class I89, class I90, class I91, class I92, class I93, class I94, class I95,
            class I96, class I97, class I98, class I99, class I100, class I101, class I102, class I103,
            class I104, class I105, class I106, class I107, class I108, class I109, class I110, class I111,
            class I112, class I113, class I114, class I115, class I116, class I117, class I118, class I119,
            class I120, class I121, class I122, class I123, class I124, class I125, class I126, class I127,
            class S0, class S1, class S2, class S3, class S4, class S5, class S6,
            class O
    >
    using mux_128_1 = dmm::assembly<
            dmm::in<
                    I0, I1, I2, I3, I4, I5, I6, I7, I8, I9, I10, I11, I12, I13, I14, I15,
                    I16, I17, I18, I19, I20, I21, I22, I23, I24, I25, I26, I27, I28, I29, I30, I31,
                    I32, I33, I34, I35, I36, I37, I38, I39, I40, I41, I42, I43, I44, I45, I46, I47,
                    I48, I49, I50, I51, I52, I53, I54, I55, I56, I57, I58, I59, I60, I61, I62, I63,
                    I64, I65, I66, I67, I68, I69, I70, I71, I72, I73, I74, I75, I76, I77, I78, I79,
                    I80, I81, I82, I83, I84, I85, I86, I87, I88, I89, I90, I91, I92, I93, I94, I95,
                    I96, I97, I98, I99, I100, I101, I102, I103, I104, I105, I106, I107, I108, I109, I110, I111,
                    I112, I113, I114, I115, I116, I117, I118, I119, I120, I121, I122, I123, I124, I125, I126, I127,
                    S0, S1, S2, S3, S4, S5, S6
            >,
            dmm::out<O>,

            mux_64_1<
                    I0*, I1*, I2*, I3*, I4*, I5*, I6*, I7*, I8*, I9*, I10*, I11*, I12*, I13*, I14*, I15*,
                    I16*, I17*, I18*, I19*, I20*, I21*, I22*, I23*, I24*, I25*, I26*, I27*, I28*, I29*, I30*, I31*,
                    I32*, I33*, I34*, I35*, I36*, I37*, I38*, I39*, I40*, I41*, I42*, I43*, I44*, I45*, I46*, I47*,
                    I48*, I49*, I50*, I51*, I52*, I53*, I54*, I55*, I56*, I57*, I58*, I59*, I60*, I61*, I62*, I63*,
                    S0*, S1*, S2*, S3*, S4*, S5*, dmm::wire<0>>,
            mux_64_1<
                    I64*, I65*, I66*, I67*, I68*, I69*, I70*, I71*, I72*, I73*, I74*, I75*, I76*, I77*, I78*, I79*,
                    I80*, I81*, I82*, I83*, I84*, I85*, I86*, I87*, I88*, I89*, I90*, I91*, I92*, I93*, I94*, I95*,
                    I96*, I97*, I98*, I99*, I100*, I101*, I102*, I103*, I104*, I105*, I106*, I107*, I108*, I109*, I110*, I111*,
                    I112*, I113*, I114*, I115*, I116*, I117*, I118*, I119*, I120*, I121*, I122*, I123*, I124*, I125*, I126*, I127*,
                    S0*, S1*, S2*, S3*, S4*, S5*, dmm::wire<1>>,
            mux_2_1<dmm::wire<0>, dmm::wire<1>, S6*, O*>
    >;

    template <
            class I0, class I1, class I2, class I3, class I4, class I5, class I6, class I7,
            class I8, class I9, class I10, class I11, class I12, class I13, class I14, class I15,
            class I16, class I17, class I18, class I19, class I20, class I21, class I22, class I23,
            class I24, class I25, class I26, class I27, class I28, class I29, class I30, class I31,
            class I32, class I33, class I34, class I35, class I36, class I37, class I38, class I39,
            class I40, class I41, class I42, class I43, class I44, class I45, class I46, class I47,
            class I48, class I49, class I50, class I51, class I52, class I53, class I54, class I55,
            class I56, class I57, class I58, class I59, class I60, class I61, class I62, class I63,
            class I64, class I65, class I66, class I67, class I68, class I69, class I70, class I71,
            class I72, class I73, class I74, class I75, class I76, class I77, class I78, class I79,
            class I80, class I81, class I82, class I83, class I84, class I85, class I86, class I87,
            class I88, class I89, class I90, class I91, class I92, class I93, class I94, class I95,
            class I96, class I97, class I98, class I99, class I100, class I101, class I102, class I103,
            class I104, class I105, class I106, class I107, class I108, class I109, class I110, class I111,
            class I112, class I113, class I114, class I115, class I116, class I117, class I118, class I119,
            class I120, class I121, class I122, class I123, class I124, class I125, class I126, class I127,
            class I128, class I129, class I130, class I131, class I132, class I133, class I134, class I135,
            class I136, class I137, class I138, class I139, class I140, class I141, class I142, class I143,
            class I144, class I145, class I146, class I147, class I148, class I149, class I150, class I151,
            class I152, class I153, class I154, class I155, class I156, class I157, class I158, class I159,
            class I160, class I161, class I162, class I163, class I164, class I165, class I166, class I167,
            class I168, class I169, class I170, class I171, class I172, class I173, class I174, class I175,
            class I176, class I177, class I178, class I179, class I180, class I181, class I182, class I183,
            class I184, class I185, class I186, class I187, class I188, class I189, class I190, class I191,
            class I192, class I193, class I194, class I195, class I196, class I197, class I198, class I199,
            class I200, class I201, class I202, class I203, class I204, class I205, class I206, class I207,
            class I208, class I209, class I210, class I211, class I212, class I213, class I214, class I215,
            class I216, class I217, class I218, class I219, class I220, class I221, class I222, class I223,
            class I224, class I225, class I226, class I227, class I228, class I229, class I230, class I231,
            class I232, class I233, class I234, class I235, class I236, class I237, class I238, class I239,
            class I240, class I241, class I242, class I243, class I244, class I245, class I246, class I247,
            class I248, class I249, class I250, class I251, class I252, class I253, class I254, class I255,
            class S0, class S1, class S2, class S3, class S4, class S5, class S6, class S7,
            class O
    >
    using mux_256_1 = dmm::assembly<
            dmm::in<
                    I0, I1, I2, I3, I4, I5, I6, I7, I8, I9, I10, I11, I12, I13, I14, I15,
                    I16, I17, I18, I19, I20, I21, I22, I23, I24, I25, I26, I27, I28, I29, I30, I31,
                    I32, I33, I34, I35, I36, I37, I38, I39, I40, I41, I42, I43, I44, I45, I46, I47,
                    I48, I49, I50, I51, I52, I53, I54, I55, I56, I57, I58, I59, I60, I61, I62, I63,
                    I64, I65, I66, I67, I68, I69, I70, I71, I72, I73, I74, I75, I76, I77, I78, I79,
                    I80, I81, I82, I83, I84, I85, I86, I87, I88, I89, I90, I91, I92, I93, I94, I95,
                    I96, I97, I98, I99, I100, I101, I102, I103, I104, I105, I106, I107, I108, I109, I110, I111,
                    I112, I113, I114, I115, I116, I117, I118, I119, I120, I121, I122, I123, I124, I125, I126, I127,
                    I128, I129, I130, I131, I132, I133, I134, I135, I136, I137, I138, I139, I140, I141, I142, I143,
                    I144, I145, I146, I147, I148, I149, I150, I151, I152, I153, I154, I155, I156, I157, I158, I159,
                    I160, I161, I162, I163, I164, I165, I166, I167, I168, I169, I170, I171, I172, I173, I174, I175,
                    I176, I177, I178, I179, I180, I181, I182, I183, I184, I185, I186, I187, I188, I189, I190, I191,
                    I192, I193, I194, I195, I196, I197, I198, I199, I200, I201, I202, I203, I204, I205, I206, I207,
                    I208, I209, I210, I211, I212, I213, I214, I215, I216, I217, I218, I219, I220, I221, I222, I223,
                    I224, I225, I226, I227, I228, I229, I230, I231, I232, I233, I234, I235, I236, I237, I238, I239,
                    I240, I241, I242, I243, I244, I245, I246, I247, I248, I249, I250, I251, I252, I253, I254, I255,
                    S0, S1, S2, S3, S4, S5, S6, S7
            >,
            dmm::out<O>,

            mux_128_1<
                    I0*, I1*, I2*, I3*, I4*, I5*, I6*, I7*, I8*, I9*, I10*, I11*, I12*, I13*, I14*, I15*,
                    I16*, I17*, I18*, I19*, I20*, I21*, I22*, I23*, I24*, I25*, I26*, I27*, I28*, I29*, I30*, I31*,
                    I32*, I33*, I34*, I35*, I36*, I37*, I38*, I39*, I40*, I41*, I42*, I43*, I44*, I45*, I46*, I47*,
                    I48*, I49*, I50*, I51*, I52*, I53*, I54*, I55*, I56*, I57*, I58*, I59*, I60*, I61*, I62*, I63*,
                    I64*, I65*, I66*, I67*, I68*, I69*, I70*, I71*, I72*, I73*, I74*, I75*, I76*, I77*, I78*, I79*,
                    I80*, I81*, I82*, I83*, I84*, I85*, I86*, I87*, I88*, I89*, I90*, I91*, I92*, I93*, I94*, I95*,
                    I96*, I97*, I98*, I99*, I100*, I101*, I102*, I103*, I104*, I105*, I106*, I107*, I108*, I109*, I110*, I111*,
                    I112*, I113*, I114*, I115*, I116*, I117*, I118*, I119*, I120*, I121*, I122*, I123*, I124*, I125*, I126*, I127*,
                    S0*, S1*, S2*, S3*, S4*, S5*, S6*, dmm::wire<0>>,
            mux_128_1<
                    I128*, I129*, I130*, I131*, I132*, I133*, I134*, I135*, I136*, I137*, I138*, I139*, I140*, I141*, I142*, I143*,
                    I144*, I145*, I146*, I147*, I148*, I149*, I150*, I151*, I152*, I153*, I154*, I155*, I156*, I157*, I158*, I159*,
                    I160*, I161*, I162*, I163*, I164*, I165*, I166*, I167*, I168*, I169*, I170*, I171*, I172*, I173*, I174*, I175*,
                    I176*, I177*, I178*, I179*, I180*, I181*, I182*, I183*, I184*, I185*, I186*, I187*, I188*, I189*, I190*, I191*,
                    I192*, I193*, I194*, I195*, I196*, I197*, I198*, I199*, I200*, I201*, I202*, I203*, I204*, I205*, I206*, I207*,
                    I208*, I209*, I210*, I211*, I212*, I213*, I214*, I215*, I216*, I217*, I218*, I219*, I220*, I221*, I222*, I223*,
                    I224*, I225*, I226*, I227*, I228*, I229*, I230*, I231*, I232*, I233*, I234*, I235*, I236*, I237*, I238*, I239*,
                    I240*, I241*, I242*, I243*, I244*, I245*, I246*, I247*, I248*, I249*, I250*, I251*, I252*, I253*, I254*, I255*,
                    S0*, S1*, S2*, S3*, S4*, S5*, S6*, dmm::wire<1>>,
            mux_2_1<dmm::wire<0>, dmm::wire<1>, S7*, O*>
    >;


    template <
            class I0_0, class I0_1, class I0_2, class I0_3, class I0_4, class I0_5, class I0_6, class I0_7,
            class I1_0, class I1_1, class I1_2, class I1_3, class I1_4, class I1_5, class I1_6, class I1_7,
            class S0,
            class O0, class O1, class O2, class O3, class O4, class O5, class O6, class O7
    >
    using mux_8_2_1 = dmm::assembly<
            dmm::in<
                    I0_0, I0_1, I0_2, I0_3, I0_4, I0_5, I0_6, I0_7,
                    I1_0, I1_1, I1_2, I1_3, I1_4, I1_5, I1_6, I1_7,
                    S0
            >,
            dmm::out<O0, O1, O2, O3, O4, O5, O6, O7>,
            mux_2_1<I0_0*, I1_0*, S0*, O0*>,
            mux_2_1<I0_1*, I1_1*, S0*, O1*>,
            mux_2_1<I0_2*, I1_2*, S0*, O2*>,
            mux_2_1<I0_3*, I1_3*, S0*, O3*>,
            mux_2_1<I0_4*, I1_4*, S0*, O4*>,
            mux_2_1<I0_5*, I1_5*, S0*, O5*>,
            mux_2_1<I0_6*, I1_6*, S0*, O6*>,
            mux_2_1<I0_7*, I1_7*, S0*, O7*>
    >;

    template <
            class I0_0, class I0_1, class I0_2, class I0_3, class I0_4, class I0_5, class I0_6, class I0_7,
            class I1_0, class I1_1, class I1_2, class I1_3, class I1_4, class I1_5, class I1_6, class I1_7,
            class I2_0, class I2_1, class I2_2, class I2_3, class I2_4, class I2_5, class I2_6, class I2_7,
            class I3_0, class I3_1, class I3_2, class I3_3, class I3_4, class I3_5, class I3_6, class I3_7,
            class S0, class S1,
            class O0, class O1, class O2, class O3, class O4, class O5, class O6, class O7
    >
    using mux_8_4_1 = dmm::assembly<
            dmm::in<
                    I0_0, I0_1, I0_2, I0_3, I0_4, I0_5, I0_6, I0_7,
                    I1_0, I1_1, I1_2, I1_3, I1_4, I1_5, I1_6, I1_7,
                    I2_0, I2_1, I2_2, I2_3, I2_4, I2_5, I2_6, I2_7,
                    I3_0, I3_1, I3_2, I3_3, I3_4, I3_5, I3_6, I3_7,
                    S0, S1
            >,
            dmm::out<O0, O1, O2, O3, O4, O5, O6, O7>,
            mux_4_1<I0_0*, I1_0*, I2_0*, I3_0*, S0*, S1*, O0*>,
            mux_4_1<I0_1*, I1_1*, I2_1*, I3_1*, S0*, S1*, O1*>,
            mux_4_1<I0_2*, I1_2*, I2_2*, I3_2*, S0*, S1*, O2*>,
            mux_4_1<I0_3*, I1_3*, I2_3*, I3_3*, S0*, S1*, O3*>,
            mux_4_1<I0_4*, I1_4*, I2_4*, I3_4*, S0*, S1*, O4*>,
            mux_4_1<I0_5*, I1_5*, I2_5*, I3_5*, S0*, S1*, O5*>,
            mux_4_1<I0_6*, I1_6*, I2_6*, I3_6*, S0*, S1*, O6*>,
            mux_4_1<I0_7*, I1_7*, I2_7*, I3_7*, S0*, S1*, O7*>
    >;
}

#endif //TRIMETA_MUX_HPP
