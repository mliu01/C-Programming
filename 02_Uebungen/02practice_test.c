#include "02practice.c"
#include "testrunner.c"

#define TEST_NAME "02practice_test"
#define TESTS_LCM 13
#define TESTS_LCM_SUM 8
#define TESTS_POWERS 9

typedef struct TestLCM
{
    int n;
    int expected;
} exercises_lcm_with_8_data;

typedef struct TestPowers
{
    int n;
    int expected;
} exercise_powers_data;

static exercises_lcm_with_8_data exercise_lcm [TESTS_LCM] = {
        {.n = 1, .expected = 8},
        {.n = 2, .expected = 8},
        {.n = 3, .expected = 24},
        {.n = 10, .expected = 40},
        {.n = 5, .expected = 40},
        {.n = 20, .expected = 40},
        {.n = 8, .expected = 8},
        {.n = 6, .expected = 24},
        {.n = 4, .expected = 8},
        {.n = 12, .expected = 24},
        {.n = 16, .expected = 16},
        {.n = 9, .expected = 72},
        {.n = 13, .expected = 104},
};

static exercises_lcm_with_8_data exercise_lcm_sum [TESTS_LCM_SUM] = {
        {.n = 1, .expected = 8},
        {.n = 2, .expected = 16},
        {.n = 3, .expected = 40},
        {.n = 6, .expected = 112},
        {.n = 10, .expected = 288},
        {.n = 32, .expected = 2768},
        {.n = 99, .expected = 26776},
        {.n = 160, .expected = 68880},
};

static exercise_powers_data exercise_powers[TESTS_POWERS] = {
        { .n = 1, .expected = 2 },
        { .n = 4, .expected = 341 },
        { .n = 0, .expected = 1 },
        { .n = 3, .expected = 40 },
        { .n = 9, .expected = 435848050 },
        { .n = 8, .expected = 19173961 },
        { .n = 5, .expected = 3906 },
        { .n = 7, .expected = 960800 },
        { .n = 2, .expected = 7 },
};

char* render_exercises_lcm_with_8(exercises_lcm_with_8_data testcase)
{
    const char *n = format_int(testcase.n);
    int len = strlen("n = ") + strlen(n) + 1;
    char *str = mallocx(len);
    snprintf(str, len, "n = %s", n);
    free((char*) n);
    return str;
}

char* render_exercise_powers(exercise_powers_data testcase)
{
    const char *n = format_int(testcase.n);
    int len = strlen("n = ") + strlen(n) + 1;
    char *str = malloc(len);
    snprintf(str, len, "n = %s", n);
    free((char*) n);
    return str;
}

int main(int argc, char const *argv[]) {
    Tester tester = tester_new(argc - 1, argv[1], argv[2],
                               "cc -std=c11 -g -Wall "TEST_NAME".c -o "TEST_NAME".o -lm && ./"TEST_NAME".o");

    /* Least common multiple with 8 */
    if(begin_exercise(&tester,"least_common_multiple_with_8","Kleinste gemeinsame Vielfache mit 8 finden."))
    {
        for (int i = 0; i < TESTS_LCM; i++)
        {
            if(begin_testcase(&tester))
            {
                char *args = render_exercises_lcm_with_8(exercise_lcm[i]);
                assert_int(&tester, exercise_lcm[i].expected, least_common_multiple_with_8(exercise_lcm[i].n), args);
                free(args);
            }
        }
    }
    /* Sum of least common multiples with 8 */
    if(begin_exercise(&tester,"sum_least_common_multiples_with_8", "Alle kleinsten gemeinsamen Vielfachen bis n summieren."))
    {
        for (int i = 0; i < TESTS_LCM_SUM; i++)
        {
            if(begin_testcase(&tester))
            {
                char *args = render_exercises_lcm_with_8(exercise_lcm_sum[i]);
                assert_int(&tester, exercise_lcm_sum[i].expected,
                           sum_least_common_multiples_with_8(exercise_lcm_sum[i].n), args);
                free(args);
            }
        }
    }
    /* Sum First Powers */
    if(begin_exercise(&tester, "sum_first_powers", "Die Potenzen von n bis zur einschließlich n-ten Potenz summieren."))
    {
        for (int i = 0; i < TESTS_POWERS; i++)
        {
            if(begin_testcase(&tester))
            {
                char *args = render_exercise_powers(exercise_powers[i]);
                assert_int(&tester, exercise_powers[i].expected, sum_first_powers(exercise_powers[i].n), args);
                free(args);
            }
        }
    }

    return wrap_up(&tester);
}