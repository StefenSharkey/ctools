/*
 * Tests for the Vector3
*/

#include <math.h>
#include <stdio.h>
#include <assert.h>

#include "../src/ct_vector.h"

int main() {
    /* Initialization */
    struct CtVector3 vector_a = ct_vector3_init(0, 0, 0);
    struct CtVector3 vector_b = ct_vector3_init(0, -10, 0);
    struct CtVector3 vector_c = ct_vector3_init(12, -10, 13);
    struct CtVector3 vector_d = ct_vector3_init(12, -10, 13);
    struct CtVector3 vector_e = ct_vector3_init(12, 5, 13);
    struct CtVector3 temp;

    assert(vector_a.vec_x == 0);
    assert(vector_a.vec_y == 0);
    assert(vector_a.vec_z == 0);

    assert(vector_b.vec_x == 0);
    assert(vector_b.vec_y == -10);
    assert(vector_b.vec_z == 0);

    assert(vector_c.vec_x == 12);
    assert(vector_c.vec_y == -10);
    assert(vector_c.vec_z == 13);
    
    /* Comparison */
    assert(ct_vector3_compare(vector_a, vector_d) == 0);
    assert(ct_vector3_compare(vector_b, vector_d) == 0);
    assert(ct_vector3_compare(vector_b, vector_b) == 1);
    assert(ct_vector3_compare(vector_d, vector_d) == 1);

    /* Adding */    
    temp = ct_vector3_add(vector_a, vector_b);
    assert(temp.vec_x == 0);
    assert(temp.vec_y == -10);
    assert(temp.vec_z == 0);

    temp = ct_vector3_add(vector_d, vector_b);
    assert(temp.vec_x == 12);
    assert(temp.vec_y == -20);
    assert(temp.vec_z == 13);

    temp = ct_vector3_add(vector_d, vector_e);
    assert(temp.vec_x == 24);
    assert(temp.vec_y == -5);
    assert(temp.vec_z == 26);

    /* Subtracting */
    temp = ct_vector3_subtract(vector_a, vector_e);
    assert(temp.vec_x == -12);
    assert(temp.vec_y == -5);
    assert(temp.vec_z == -13);

    temp = ct_vector3_subtract(vector_b, vector_e);
    assert(temp.vec_x == -12);
    assert(temp.vec_y == -15);
    assert(temp.vec_z == -13);

    temp = ct_vector3_subtract(vector_b, vector_e);
    assert(temp.vec_x == -12);
    assert(temp.vec_y == -15);
    assert(temp.vec_z == -13);

    temp = ct_vector3_subtract(vector_e, vector_e);
    assert(temp.vec_x == 0);
    assert(temp.vec_y == 0);
    assert(temp.vec_z == 0);

    /* Multiplying */
    temp = ct_vector3_multiply(vector_e, vector_e);
    assert(temp.vec_x == 144);
    assert(temp.vec_y == 25);
    assert(temp.vec_z == 169);

    temp = ct_vector3_multiply(vector_a, vector_b);
    assert(temp.vec_x == 0);
    assert(temp.vec_y == 0);
    assert(temp.vec_z == 0);

    temp = ct_vector3_multiply(vector_d, vector_b);
    assert(temp.vec_x == 0);
    assert(temp.vec_y == 100);
    assert(temp.vec_z == 0);

    temp = ct_vector3_multiply(vector_e, vector_c);
    assert(temp.vec_x == 144);
    assert(temp.vec_y == -50);
    assert(temp.vec_z == 169);

    /* Dividing */
    temp = ct_vector3_divide(vector_c, vector_d);
    assert(temp.vec_x == 1);
    assert(temp.vec_y == 1);
    assert(temp.vec_z == 1);

    temp = ct_vector3_divide(vector_e, vector_d);
    assert(temp.vec_x == 1);
    assert(temp.vec_y == -0.5);
    assert(temp.vec_z == 1);

    temp = ct_vector3_divide(vector_a, vector_d);
    assert(temp.vec_x == 0);
    assert(temp.vec_y == 0);
    assert(temp.vec_z == 0);

    temp = ct_vector3_divide(vector_d, vector_e);
    assert(temp.vec_x == 1);
    assert(temp.vec_y == -2);
    assert(temp.vec_z == 1);

    /* Scaling */
    temp = ct_vector3_scale(vector_d, 2);
    assert(temp.vec_x == 24);
    assert(temp.vec_y == -20);
    assert(temp.vec_z == 26);

    temp = ct_vector3_scale(vector_d, -2);
    assert(temp.vec_x == -24);
    assert(temp.vec_y == 20);
    assert(temp.vec_z == -26);

    temp = ct_vector3_scale(vector_d, -2.5);
    assert(temp.vec_x == -30);
    assert(temp.vec_y == 25);
    assert(temp.vec_z == -32.5);

    temp = ct_vector3_scale(vector_d, -1);
    assert(temp.vec_x == -12);
    assert(temp.vec_y == 10);
    assert(temp.vec_z == -13);

    temp = ct_vector3_scale(vector_d, 1);
    assert(temp.vec_x == 12);
    assert(temp.vec_y == -10);
    assert(temp.vec_z == 13);

    temp = ct_vector3_scale(vector_d, 0.5);
    assert(temp.vec_x == 6);
    assert(temp.vec_y == -5);
    assert(temp.vec_z == 6.5);

    /* Magnitude */
    assert(ct_vector3_magnitude(vector_a) == 0);
    assert(ct_vector3_magnitude(vector_c) == 20.322401432901575);
    assert(ct_vector3_magnitude(vector_e) == 18.384776310850235);
    assert(ct_vector3_magnitude(vector_b) == 10);

    /* Normalizing */
    temp = ct_vector3_unit(vector_b);
    assert(temp.vec_x == 0);
    assert(temp.vec_y == -1);
    assert(temp.vec_z == 0);

    temp = ct_vector3_unit(vector_d);
    assert(temp.vec_x == 0.5904813975661475);
    assert(temp.vec_y == -0.4920678313051229);
    assert(temp.vec_z == 0.6396881806966598);

    /* NAN, so this cannot be compared
    temp = ct_vector3_unit(vector_a);
    assert(temp.vec_x == (double) -NAN);
    assert(temp.vec_y == (double) -NAN);
    assert(temp.vec_z == (double) -NAN);
    */

    /*
    struct CtVector3 vector_a = ct_vector3_init(0, 0, 0);
    struct CtVector3 vector_b = ct_vector3_init(0, -10, 0);
    struct CtVector3 vector_c = ct_vector3_init(12, -10, 13);
    struct CtVector3 vector_d = ct_vector3_init(12, -10, 13);
    struct CtVector3 vector_e = ct_vector3_init(12, 5, 13);
    */

    return 0;
}
