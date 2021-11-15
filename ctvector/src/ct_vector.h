#ifndef CT_VECTOR_H
#define CT_VECTOR_H

/*
 * A collection of vector fields
*/
struct CtVector3 {
    double vec_x;
    double vec_y;
    double vec_z;
};

/*
 * Initializes a new Vector3 object.
 *
 * @param x: the x coordinate
 * @param y: the y coordinate
 * @param z: the z coordinate
 * @return: a new Vector3
*/
struct CtVector3 ct_vector3_init(double x, double y, double z);

/*
 * Compares a Vector3 to another Vector3 by comparing their components.
 *
 * @param vector_a: the first vector
 * @param vector_a: the second vector
 * @return: 1 if the vectors are the same, 0 if they are not the same
*/
int ct_vector3_compare(struct CtVector3 vector_a, struct CtVector3 vector_b);

/*
 * Combines two Vector3's by adding their components
 *
 * @param a: the first vector
 * @param b: the second vector
 * @return: the combined vector
*/
struct CtVector3 ct_vector3_add(struct CtVector3 a, struct CtVector3 b);

/*
 * Subtracts two Vector3's by subtracting their components
 *
 * @param a: the first vector
 * @param b: the second vector
 * @return: the subtracted vector
*/ struct CtVector3 ct_vector3_subtract(struct CtVector3 a, struct CtVector3 b);
/*
 * Multiplies two vectors together, where the resulting Vector is the product
 * of each component.
 *
 * @param a: the first vector
 * @param b: the second vector
 * @return: the multiplied vector
*/
struct CtVector3 ct_vector3_multiply(struct CtVector3 a, struct CtVector3 b);

/*
 * Divides two vectors together, where the resulting Vector is the quotient
 * of each component.
 *
 * @param a: the first vector
 * @param b: the second vector
 * @return: the multiplied vector
*/
struct CtVector3 ct_vector3_divide(struct CtVector3 a, struct CtVector3 b);

/*
 * 'Scales' each component of a vector by a scalar, returning the scaled vector.
 *
 * @param vector: the vector to scale
 * @param scalar: the number to scale the vector by
 * @return: the scaled vector
*/
struct CtVector3 ct_vector3_scale(struct CtVector3 vector, double scalar);

/*
 * Calculates the magnitude (length) of a Vector.
 *
 * @param vector: the vector to calculate the magnitude of
 * @return: the magnitude of the vector
*/
double ct_vector3_magnitude(struct CtVector3 vector);

/*
 * Calculates a 'normalized' version of a vector, with the
 * same direction, but a length of 1.
 *
 * @param vector: the vector to normalize
 * @return: the normalized vector
*/
struct CtVector3 ct_vector3_unit(struct CtVector3 vector);









#endif
