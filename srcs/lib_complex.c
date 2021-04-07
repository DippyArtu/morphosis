/* *********************************** */
/*                                     */
/*      Morphosis project              */
/*                                     */
/*      Created by Artur Makhnach      */
/*      github.com/DippyArtu           */
/*      artum.me                       */
/*                                     */
/* *********************************** */

#include <lib_complex.h>

TYPE			cl_creal(const cl_complex n)
{
	return(n.x);
}

TYPE			cl_cimag(const cl_complex n)
{
	return(n.y);
}

/*
 * Returns modulus of complex number (its length):
 */
TYPE			cl_cmod(const cl_complex n)
{
	return(sqrt((TYPE)((n.x * n.x) + (n.y * n.y))));
}

/*
 The dot product of two vectors a = [a1, a2, ..., an] and b = [b1, b2, ..., bn] is defined as:
 d = a1b1 + a2b2
*/
TYPE			cl_cdot(const cl_complex a, const cl_complex b)
{
	return((a.x * b.x) + (a.y * b.y));
}

cl_complex		cl_cadd(const cl_complex a, const cl_complex b)
{
	cl_complex		res;

	res.x = a.x + b.x;
	res.y = a.y + b.y;
	return(res);
}

cl_complex 		cl_cmult(const cl_complex a, const cl_complex b)
{
	cl_complex		res;

	res.x = (a.x * b.x - a.y * b.y);
	res.y = (a.x * b.y + a.y * b.x);
	return (res);
}

/*
 * Computes the integer power of a complex number.
*/
cl_complex 		cl_cpow(const cl_complex base , int exp)
{
	cl_complex	res;

	res.x = 1;
	res.y = 1;
	while(exp)
	{
		if(exp & 1)
			res=cl_cmult(res, base);
		exp>>= 1;
		res = cl_cmult(res, res);
	}
	return (res);
}

cl_complex 		cl_cdiv(const cl_complex a, const cl_complex b)
{
	TYPE		dividend;
	cl_complex	res;

	dividend = (b.x * b.x + b.y * b.y);
	res.x = ((a.x * b.x + a.y * b.y) / dividend);
	res.y = ((a.y * b.x - a.x * b.y) / dividend);
	return(res);
}

/*
 * Get the argument of a complex number (its angle):
 * http://en.wikipedia.org/wiki/Complex_number#Absolute_value_and_argument
 */
TYPE 			cl_carg(const cl_complex a)
{
	if(a.x > 0)
		return(atan((TYPE)(a.y / a.x)));
	else if(a.x < 0 && a.y >= 0)
		return(atan((TYPE)(a.y / a.x)) + Pi_cl);
	else if(a.x < 0 && a.y < 0)
		return(atan((TYPE)(a.y / a.x)) - Pi_cl);
	else if(a.x == 0 && a.y > 0)
		return((TYPE)(Pi_cl / 2));
	else if(a.x == 0 && a.y < 0)
		return((TYPE)(Pi_cl * -1) / 2);
	else
		return(0);
}

/*
 *  Returns the Square root of complex number.
 *  Although a complex number has two square roots,
 *  only  one of them -the principal square root- is computed.
 *  see wikipedia:http://en.wikipedia.org/wiki/Square_root#Principal_square_root_of_a_complex_number
 */
cl_complex 		cl_csqrt(const cl_complex n)
{
	const TYPE sm = sqrt((TYPE)(cl_cmod(n)));
	const TYPE a2 = cl_carg(n) / 2;
	const TYPE ca2 = cos((TYPE)a2);
	const TYPE sa2 = sin((TYPE)a2);
	cl_complex	res;

	res.x = sm * ca2;
	res.y = sm * sa2;
	return(res);
}

/*
 * Computes the exponential function for the complex number z = x+iy
 * as: exp(z) = e^x(cos(y) + isin(y))
 * See: https://en.wikipedia.org/wiki/Exponential_function#Complex_plane
*/
cl_complex 		cl_cexp(const cl_complex n)
{
	const TYPE e = exp((TYPE)n.x);
	cl_complex	res;

	res.x = (e * cos((TYPE)n.y));
	res.y = (e * sin((TYPE)n.y));
	return(res);
}

/*
 * Computes the logatirm of the complex number z= x+iy
 * x+iy = re^{i\theta}
 * log(x+iy) = log(re^{i\theta} = log(r)+log(e^{i\theta}
 * where r is the module of |z| = sqrt(x^2+y^2)
 * log(z) = log(|z|) + iarg(z) = log(sqrt(x^2+y^2) + i atan(y/b)
 *
 * */
cl_complex 		cl_clog(const cl_complex z)
{
	cl_complex	res;

	res.x = log((TYPE)cl_cmod(z));
	res.y = cl_carg(z);
	return(res);
}


/*
 * Returns the product of 2 quaternions
 */
cl_quat			cl_quat_mult(cl_quat q1, cl_quat q2)
{
	cl_quat 	res;

	res.x = (q1.x * q2.x) - (q1.y * q2.y) - (q1.z * q2.z) - (q1.w * q2.w);
	res.y = (q1.x * q2.y) + (q1.y * q2.x) + (q1.z * q2.w) - (q1.w * q2.z);
	res.z = (q1.x * q2.z) + (q1.z * q2.x) + (q1.w * q2.y) - (q1.y * q2.w);
	res.w = (q1.x * q1.w) + (q1.w * q2.x) + (q1.y * q2.z) - (q1.z * q2.y);
	return res;
}

/*
 * Returns the sum of 2 quaternions
 */
cl_quat 		cl_quat_sum(cl_quat q1, cl_quat q2)
{
	cl_quat 	res;

	res.x = q1.x + q2.x;
	res.y = q1.y + q2.y;
	res.z = q1.z + q2.z;
	res.w = q1.w + q2.w;
	return res;
}

/*
 * Returns the conjugate of a quaternion
 *
 * The conjugate of a quaternion number is a quaternion
 * with the same magnitudes but with the sign of the imaginary parts inverted
 */
cl_quat 		cl_quat_conjugate(cl_quat q)
{
	cl_quat 	res;

	res.x = q.x;
	res.y = -1 * q.y;
	res.z = -1 * q.z;
	res.w = -1 * q.w;
	return res;
}

/*
 * Returns modulus of quaternion (its length):
 */
TYPE 			cl_quat_mod(cl_quat q)
{
	cl_quat 	tmp;

	tmp = cl_quat_conjugate(q);
	tmp = cl_quat_mult(q, tmp);
	return (sqrt((TYPE)((tmp.x * tmp.x) + (tmp.y * tmp.y) + (tmp.z * tmp.z) + (tmp.w * tmp.w))));
}
