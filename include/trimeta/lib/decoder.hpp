//
// Created by Mark on 9/26/2019.
//

#ifndef TRIMETA_DECODER_HPP
#define TRIMETA_DECODER_HPP

#include <dimeta/macro/macro.hpp>
#include <trimeta/unit_primitives.hpp>

namespace tm::lib {
    namespace dmm = dm::macro;

    template <
            class S0,
            class O0, class O1
    >
    using decoder_1_2 = dmm::assembly<
            dmm::in<S0>,
            dmm::out<O0, O1>,
            unit_buf<S0*, O0*>,
            unit_not<S0*, O1*>
    >;

    template <
            class E, class S0,
            class O0, class O1
    >
    using decoder_1_2_e = dmm::assembly<
            dmm::in<E, S0>,
            dmm::out<O0, O1>,
            unit_and2<E*, S0*, O0*>,
            unit_not<S0*, dmm::wire<0>>,
            unit_and2<E*, dmm::wire<0>, O1*>
    >;

    template <
            class S0, class S1,
            class O0, class O1, class O2, class O3
    >
    using decoder_2_4 = dmm::assembly<
            dmm::in<S0, S1>,
            dmm::out<O0, O1, O2, O3>,

            unit_not<S0*, dmm::wire<0>>,
            unit_not<S1*, dmm::wire<1>>,

            unit_and2<dmm::wire<0>, dmm::wire<1>, O0*>,
            unit_and2<dmm::wire<0>, S1*, O1*>,
            unit_and2<S0*, dmm::wire<1>, O2*>,
            unit_and2<S0*, S1*, O3*>
    >;

    template <
            class E, class S0, class S1,
            class O0, class O1, class O2, class O3
    >
    using decoder_2_4_e = dmm::assembly<
            dmm::in<E, S0, S1>,
            dmm::out<O0, O1, O2, O3>,

            unit_not<S0*, dmm::wire<0>>,
            unit_not<S1*, dmm::wire<1>>,

            unit_and2<dmm::wire<0>, dmm::wire<1>, dmm::wire<'O', 0>>,
            unit_and2<dmm::wire<0>, S1*, dmm::wire<'O', 1>>,
            unit_and2<S0*, dmm::wire<1>, dmm::wire<'O', 2>>,
            unit_and2<S0*, S1*, dmm::wire<'O', 3>>,

            unit_and2<E*, dmm::wire<'O', 0>, O0*>,
            unit_and2<E*, dmm::wire<'O', 1>, O1*>,
            unit_and2<E*, dmm::wire<'O', 2>, O2*>,
            unit_and2<E*, dmm::wire<'O', 3>, O3*>
    >;

    template <
            class S0, class S1, class S2, class S3,
            class O0, class O1, class O2, class O3, class O4, class O5, class O6, class O7,
            class O8, class O9, class O10, class O11, class O12, class O13, class O14, class O15
    >
    using decoder_4_16 = dmm::assembly<
            dmm::in<S0, S1, S2, S3>,
            dmm::out<O0, O1, O2, O3, O4, O5, O6, O7, O8, O9, O10, O11, O12, O13, O14, O15>,

            decoder_2_4<S2*, S3*, dmm::wire<'E', 0>, dmm::wire<'E', 1>, dmm::wire<'E', 2>, dmm::wire<'E', 3>>,

            decoder_2_4_e<dmm::wire<'E', 0>, S0*, S1*, O0*, O1*, O2*, O3*>,
            decoder_2_4_e<dmm::wire<'E', 1>, S0*, S1*, O4*, O5*, O6*, O7*>,
            decoder_2_4_e<dmm::wire<'E', 2>, S0*, S1*, O8*, O9*, O10*, O11*>,
            decoder_2_4_e<dmm::wire<'E', 3>, S0*, S1*, O12*, O13*, O14*, O15*>
    >;

    template <
            class E, class S0, class S1, class S2, class S3,
            class O0, class O1, class O2, class O3, class O4, class O5, class O6, class O7,
            class O8, class O9, class O10, class O11, class O12, class O13, class O14, class O15
    >
    using decoder_4_16_e = dmm::assembly<
            dmm::in<E, S0, S1, S2, S3>,
            dmm::out<
                    O0, O1, O2, O3, O4, O5, O6, O7,
                    O8, O9, O10, O11, O12, O13, O14, O15
            >,

            decoder_2_4_e<E*, S2*, S3*, dmm::wire<'E', 0>, dmm::wire<'E', 1>, dmm::wire<'E', 2>, dmm::wire<'E', 3>>,

            decoder_2_4_e<dmm::wire<'E', 0>, S0*, S1*, O0*, O1*, O2*, O3*>,
            decoder_2_4_e<dmm::wire<'E', 1>, S0*, S1*, O4*, O5*, O6*, O7*>,
            decoder_2_4_e<dmm::wire<'E', 2>, S0*, S1*, O8*, O9*, O10*, O11*>,
            decoder_2_4_e<dmm::wire<'E', 3>, S0*, S1*, O12*, O13*, O14*, O15*>
    >;

    template <
            class E, class S0, class S1, class S2, class S3, class S4, class S5, class S6, class S7,
            class O0, class O1, class O2, class O3, class O4, class O5, class O6, class O7,
            class O8, class O9, class O10, class O11, class O12, class O13, class O14, class O15,
            class O16, class O17, class O18, class O19, class O20, class O21, class O22, class O23,
            class O24, class O25, class O26, class O27, class O28, class O29, class O30, class O31,
            class O32, class O33, class O34, class O35, class O36, class O37, class O38, class O39,
            class O40, class O41, class O42, class O43, class O44, class O45, class O46, class O47,
            class O48, class O49, class O50, class O51, class O52, class O53, class O54, class O55,
            class O56, class O57, class O58, class O59, class O60, class O61, class O62, class O63,
            class O64, class O65, class O66, class O67, class O68, class O69, class O70, class O71,
            class O72, class O73, class O74, class O75, class O76, class O77, class O78, class O79,
            class O80, class O81, class O82, class O83, class O84, class O85, class O86, class O87,
            class O88, class O89, class O90, class O91, class O92, class O93, class O94, class O95,
            class O96, class O97, class O98, class O99, class O100, class O101, class O102, class O103,
            class O104, class O105, class O106, class O107, class O108, class O109, class O110, class O111,
            class O112, class O113, class O114, class O115, class O116, class O117, class O118, class O119,
            class O120, class O121, class O122, class O123, class O124, class O125, class O126, class O127,
            class O128, class O129, class O130, class O131, class O132, class O133, class O134, class O135,
            class O136, class O137, class O138, class O139, class O140, class O141, class O142, class O143,
            class O144, class O145, class O146, class O147, class O148, class O149, class O150, class O151,
            class O152, class O153, class O154, class O155, class O156, class O157, class O158, class O159,
            class O160, class O161, class O162, class O163, class O164, class O165, class O166, class O167,
            class O168, class O169, class O170, class O171, class O172, class O173, class O174, class O175,
            class O176, class O177, class O178, class O179, class O180, class O181, class O182, class O183,
            class O184, class O185, class O186, class O187, class O188, class O189, class O190, class O191,
            class O192, class O193, class O194, class O195, class O196, class O197, class O198, class O199,
            class O200, class O201, class O202, class O203, class O204, class O205, class O206, class O207,
            class O208, class O209, class O210, class O211, class O212, class O213, class O214, class O215,
            class O216, class O217, class O218, class O219, class O220, class O221, class O222, class O223,
            class O224, class O225, class O226, class O227, class O228, class O229, class O230, class O231,
            class O232, class O233, class O234, class O235, class O236, class O237, class O238, class O239,
            class O240, class O241, class O242, class O243, class O244, class O245, class O246, class O247,
            class O248, class O249, class O250, class O251, class O252, class O253, class O254, class O255
    >
    using decoder_8_256_e = dmm::assembly<
            dmm::in<E, S0, S1, S2, S3, S4, S5, S6, S7>,
            dmm::out<
                    O0, O1, O2, O3, O4, O5, O6, O7,
                    O8, O9, O10, O11, O12, O13, O14, O15,
                    O16, O17, O18, O19, O20, O21, O22, O23,
                    O24, O25, O26, O27, O28, O29, O30, O31,
                    O32, O33, O34, O35, O36, O37, O38, O39,
                    O40, O41, O42, O43, O44, O45, O46, O47,
                    O48, O49, O50, O51, O52, O53, O54, O55,
                    O56, O57, O58, O59, O60, O61, O62, O63,
                    O64, O65, O66, O67, O68, O69, O70, O71,
                    O72, O73, O74, O75, O76, O77, O78, O79,
                    O80, O81, O82, O83, O84, O85, O86, O87,
                    O88, O89, O90, O91, O92, O93, O94, O95,
                    O96, O97, O98, O99, O100, O101, O102, O103,
                    O104, O105, O106, O107, O108, O109, O110, O111,
                    O112, O113, O114, O115, O116, O117, O118, O119,
                    O120, O121, O122, O123, O124, O125, O126, O127,
                    O128, O129, O130, O131, O132, O133, O134, O135,
                    O136, O137, O138, O139, O140, O141, O142, O143,
                    O144, O145, O146, O147, O148, O149, O150, O151,
                    O152, O153, O154, O155, O156, O157, O158, O159,
                    O160, O161, O162, O163, O164, O165, O166, O167,
                    O168, O169, O170, O171, O172, O173, O174, O175,
                    O176, O177, O178, O179, O180, O181, O182, O183,
                    O184, O185, O186, O187, O188, O189, O190, O191,
                    O192, O193, O194, O195, O196, O197, O198, O199,
                    O200, O201, O202, O203, O204, O205, O206, O207,
                    O208, O209, O210, O211, O212, O213, O214, O215,
                    O216, O217, O218, O219, O220, O221, O222, O223,
                    O224, O225, O226, O227, O228, O229, O230, O231,
                    O232, O233, O234, O235, O236, O237, O238, O239,
                    O240, O241, O242, O243, O244, O245, O246, O247,
                    O248, O249, O250, O251, O252, O253, O254, O255
            >,

            decoder_4_16_e<
                    E*, S4*, S5*, S6*, S7*,
                    dmm::wire<'E', 0>, dmm::wire<'E', 1>, dmm::wire<'E', 2>, dmm::wire<'E', 3>,
                    dmm::wire<'E', 4>, dmm::wire<'E', 5>, dmm::wire<'E', 6>, dmm::wire<'E', 7>,
                    dmm::wire<'E', 8>, dmm::wire<'E', 9>, dmm::wire<'E', 10>, dmm::wire<'E', 11>,
                    dmm::wire<'E', 12>, dmm::wire<'E', 13>, dmm::wire<'E', 14>, dmm::wire<'E', 15>
            >,
            decoder_4_16_e<dmm::wire<'E', 0>, S0*, S1*, S2*, S3*, O0*, O1*, O2*, O3*, O4*, O5*, O6*, O7*, O8*, O9*, O10*, O11*, O12*, O13*, O14*, O15*>,
            decoder_4_16_e<dmm::wire<'E', 1>, S0*, S1*, S2*, S3*, O16*, O17*, O18*, O19*, O20*, O21*, O22*, O23*, O24*, O25*, O26*, O27*, O28*, O29*, O30*, O31*>,
            decoder_4_16_e<dmm::wire<'E', 2>, S0*, S1*, S2*, S3*, O32*, O33*, O34*, O35*, O36*, O37*, O38*, O39*, O40*, O41*, O42*, O43*, O44*, O45*, O46*, O47*>,
            decoder_4_16_e<dmm::wire<'E', 3>, S0*, S1*, S2*, S3*, O48*, O49*, O50*, O51*, O52*, O53*, O54*, O55*, O56*, O57*, O58*, O59*, O60*, O61*, O62*, O63*>,
            decoder_4_16_e<dmm::wire<'E', 4>, S0*, S1*, S2*, S3*, O64*, O65*, O66*, O67*, O68*, O69*, O70*, O71*, O72*, O73*, O74*, O75*, O76*, O77*, O78*, O79*>,
            decoder_4_16_e<dmm::wire<'E', 5>, S0*, S1*, S2*, S3*, O80*, O81*, O82*, O83*, O84*, O85*, O86*, O87*, O88*, O89*, O90*, O91*, O92*, O93*, O94*, O95*>,
            decoder_4_16_e<dmm::wire<'E', 6>, S0*, S1*, S2*, S3*, O96*, O97*, O98*, O99*, O100*, O101*, O102*, O103*, O104*, O105*, O106*, O107*, O108*, O109*, O110*, O111*>,
            decoder_4_16_e<dmm::wire<'E', 7>, S0*, S1*, S2*, S3*, O112*, O113*, O114*, O115*, O116*, O117*, O118*, O119*, O120*, O121*, O122*, O123*, O124*, O125*, O126*, O127*>,
            decoder_4_16_e<dmm::wire<'E', 8>, S0*, S1*, S2*, S3*, O128*, O129*, O130*, O131*, O132*, O133*, O134*, O135*, O136*, O137*, O138*, O139*, O140*, O141*, O142*, O143*>,
            decoder_4_16_e<dmm::wire<'E', 9>, S0*, S1*, S2*, S3*, O144*, O145*, O146*, O147*, O148*, O149*, O150*, O151*, O152*, O153*, O154*, O155*, O156*, O157*, O158*, O159*>,
            decoder_4_16_e<dmm::wire<'E', 10>, S0*, S1*, S2*, S3*, O160*, O161*, O162*, O163*, O164*, O165*, O166*, O167*, O168*, O169*, O170*, O171*, O172*, O173*, O174*, O175*>,
            decoder_4_16_e<dmm::wire<'E', 11>, S0*, S1*, S2*, S3*, O176*, O177*, O178*, O179*, O180*, O181*, O182*, O183*, O184*, O185*, O186*, O187*, O188*, O189*, O190*, O191*>,
            decoder_4_16_e<dmm::wire<'E', 12>, S0*, S1*, S2*, S3*, O192*, O193*, O194*, O195*, O196*, O197*, O198*, O199*, O200*, O201*, O202*, O203*, O204*, O205*, O206*, O207*>,
            decoder_4_16_e<dmm::wire<'E', 13>, S0*, S1*, S2*, S3*, O208*, O209*, O210*, O211*, O212*, O213*, O214*, O215*, O216*, O217*, O218*, O219*, O220*, O221*, O222*, O223*>,
            decoder_4_16_e<dmm::wire<'E', 14>, S0*, S1*, S2*, S3*, O224*, O225*, O226*, O227*, O228*, O229*, O230*, O231*, O232*, O233*, O234*, O235*, O236*, O237*, O238*, O239*>,
            decoder_4_16_e<dmm::wire<'E', 15>, S0*, S1*, S2*, S3*, O240*, O241*, O242*, O243*, O244*, O245*, O246*, O247*, O248*, O249*, O250*, O251*, O252*, O253*, O254*, O255*>
    >;
}

#endif //TRIMETA_DECODER_HPP
