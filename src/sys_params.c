
/* local includes */
// #include "lqrsim.h"
// #include "main.h"
// #include "plclib.h"
// #include "standup.h"
// #include "pos.h"

/* self include */
#include "sys_params.h"

/*
 *  General parameters
 */

const general_params_t p1_general_params = {
    .offsPend = 21757,  // calibrated
    .theta_gl = 0.1,
    .theta_gl2 = 0.01,
    .calibrated_PI = 2.94836,
    .v_gl = 0.08,       // calibrated
    .theta_180_delay = 100 * MSEC,
    .theta_180_epsilon = 0.235,
    .theta_d_0_delay = 100 * MSEC,
    .theta_d_0_epsilon = 0.03,
};

const general_params_t p2_general_params = {
    .offsPend = 19845,  // calibrated different to p1
    .theta_gl = 0.1,
    .theta_gl2 = 0.01,
    .calibrated_PI = 2.94836,
    .v_gl = 0.1,   // calibrated different to p1
    .theta_180_delay = 100 * MSEC,
    .theta_180_epsilon = 0.235,
    .theta_d_0_delay = 100 * MSEC,
    .theta_d_0_epsilon = 0.03,
};

/*
    Manual parameters
*/

const manual_params_t p1_manual_params = {
    .v_manual = 0.2,  // [m/s] velocity
    .a_manual = 0.5,  // [m/s²] acceleration
};

const manual_params_t p2_manual_params = {
    .v_manual = 0.2,  // [m/s] velocity
    .a_manual = 0.5,  // [m/s²] acceleration
};

/*
 *   Stand up parameters
 */

const standup_params_t p1_standup_params = {
    // This should be zero, because it is set to 0.0 at auto mode start
    // .v_standup = 2.0,  // [m/s] velocity
    .v_standup = 0.2,  // [m/s] velocity
    .a_standup = 0.5,  // [m/s²] acceleration
};

const standup_params_t p2_standup_params = {
    // This should be zero, because it is set to 0.0 at auto mode start
    // .v_standup = 2.0,  // [m/s] velocity
    .v_standup = 0.2,  // [m/s] velocity
    .a_standup = 0.5,  // [m/s²] acceleration
};

#define V_MAX_ALL 0.4
#define A_MAX_ALL 2.0

#define DUR_0 (100 * MSEC)
#define DUR_1 (DUR_0 + 450 * MSEC)
#define DUR_2 (DUR_1 + 550 * MSEC)
#define DUR_3 (DUR_2 + 550 * MSEC)
#define DUR_4 (DUR_3 + 550 * MSEC)
#define DUR_5 (DUR_4 + 550 * MSEC)
#define DUR_6 (DUR_5 + 820 * MSEC)
#define DUR_7 (DUR_6 + 810 * MSEC)
#define DUR_8 (DUR_7 + 500 * MSEC)
#define DUR_9 (DUR_8 + 500 * MSEC)
#define DUR_10 (DUR_9 + 200 * MSEC)

/* currently we use the same parameters for both pendulums */

const standup_moves_t p1_standup_moves = {
    [0] = {.pos = 0.08, .vel = 0.1, .acc = A_MAX_ALL, .time = DUR_0},
    [1] = {.pos = -0.08, .vel = V_MAX_ALL, .acc = A_MAX_ALL, .time = DUR_1},
    [2] = {.pos = 0.08, .vel = V_MAX_ALL, .acc = A_MAX_ALL, .time = DUR_2},
    [3] = {.pos = -0.08, .vel = V_MAX_ALL, .acc = A_MAX_ALL, .time = DUR_3},
    [4] = {.pos = 0.08, .vel = V_MAX_ALL, .acc = A_MAX_ALL, .time = DUR_4},
    [5] = {.pos = -0.08, .vel = V_MAX_ALL, .acc = A_MAX_ALL, .time = DUR_5},
    [6] = {.pos = 0.08, .vel = V_MAX_ALL, .acc = A_MAX_ALL, .time = DUR_6},
    [7] = {.pos = -0.08, .vel = V_MAX_ALL, .acc = A_MAX_ALL, .time = DUR_7},
    [8] = {.pos = -0.01, .vel = V_MAX_ALL, .acc = A_MAX_ALL, .time = DUR_2},
    [9] = {.pos = 0.0, .vel = 0.0, .acc = A_MAX_ALL, .time = DUR_9},
    [10] = {.pos = 0.0, .vel = 0.0, .acc = A_MAX_ALL, .time = DUR_10},
};

const standup_moves_t p2_standup_moves = {
    [0] = {.pos = 0.08, .vel = 0.1, .acc = A_MAX_ALL, .time = DUR_0},
    [1] = {.pos = -0.08, .vel = V_MAX_ALL, .acc = A_MAX_ALL, .time = DUR_1},
    [2] = {.pos = 0.08, .vel = V_MAX_ALL, .acc = A_MAX_ALL, .time = DUR_2},
    [3] = {.pos = -0.08, .vel = V_MAX_ALL, .acc = A_MAX_ALL, .time = DUR_3},
    [4] = {.pos = 0.08, .vel = V_MAX_ALL, .acc = A_MAX_ALL, .time = DUR_4},
    [5] = {.pos = -0.08, .vel = V_MAX_ALL, .acc = A_MAX_ALL, .time = DUR_5},
    [6] = {.pos = 0.08, .vel = V_MAX_ALL, .acc = A_MAX_ALL, .time = DUR_6},
    [7] = {.pos = -0.08, .vel = V_MAX_ALL, .acc = A_MAX_ALL, .time = DUR_7},
    [8] = {.pos = -0.01, .vel = V_MAX_ALL, .acc = A_MAX_ALL, .time = DUR_2},
    [9] = {.pos = 0.0, .vel = 0.0, .acc = A_MAX_ALL, .time = DUR_9},
    [10] = {.pos = 0.0, .vel = 0.0, .acc = A_MAX_ALL, .time = DUR_10},
};

/*
 *   LQR and Sim parameters
 */

const lqr_sim_params_t p1_lqr_sim_params = {
    .m_axis = 2.3,   // [kg]
    .F_max = 800.0,  // [N]
    // .v_max = 2.0,  global 2.0 is overwritten by 1.0 in pos code
    .v_max = 1.0,  // [m/s]

    .K_x = 89.0,
    .K_v = 97.0,
    .K_t = 361.0,
    .K_td = 40.0,
};

const lqr_sim_params_t p2_lqr_params = {
    .m_axis = 2.3,   // [kg]
    .F_max = 800.0,  // [N]
    .v_max = 2.0,    // [m/s]

    .K_x = 89.0,
    .K_v = 97.0,
    .K_t = 361.0,
    .K_td = 40.0,
};

/*
 *  Pos parameters
 */

const pos_params_t p1_pos_params = {
    .K_v = 0.03,        // Weight for calculating v_soll
    .factor = 10.0,     // ??
    .epsilon_x = 0.005  // [m],
};

const pos_params_t p2_pos_params = {
    .K_v = 0.03,        // Weight for calculating v_soll
    .factor = 10.0,     // ??
    .epsilon_x = 0.005  // [m],
};

/*
 * Main parameters
 * These are just collectios of parameters for the instances of POU main
 */

const main_params_t p1_main_params = {.man_params = &p1_manual_params,
                                      .su_params = &p1_standup_params,
                                      .su_moves = &p1_standup_moves,
                                      .ls_params = &p1_lqr_sim_params,
                                      .pos_params = &p1_pos_params};

const main_params_t p2_main_params = {.man_params = &p2_manual_params,
                                      .su_params = &p2_standup_params,
                                      .su_moves = &p2_standup_moves,
                                      .ls_params = &p2_lqr_params,
                                      .pos_params = &p2_pos_params};
