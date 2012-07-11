/*
	Copyright (c) 2011, T. Kroes <t.kroes@tudelft.nl>
	All rights reserved.

	Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:

	- Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
	- Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.
	- Neither the name of the TU Delft nor the names of its contributors may be used to endorse or promote products derived from this software without specific prior written permission.
	
	THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#pragma once

#include <cuda_runtime.h>

#include "montecarlo.h"
										
namespace ExposureRender
{

HOST_DEVICE inline float GlossinessExponent(const float& Glossiness)
{
	return 1000000.0f * powf(Glossiness, 7);
}

HOST_DEVICE_NI inline float Gauss2D(const float& Sigma, const float& X, const float& Y)
{
	return expf(-((X * X + Y * Y) / (2 * Sigma * Sigma)));
}

HOST_DEVICE inline float G(Vec3f P1, Vec3f N1, Vec3f P2, Vec3f N2)
{
	const Vec3f W = Normalize(P2 - P1);
	return (ClampedDot(W, N1) * ClampedDot(-1.0f * W, N2)) / LengthSquared(P1, P2);
}

template<class T>
HOST_DEVICE inline T CumulativeMovingAverage(const T& A, const T& Ax, const int& N)
{
	return A + (Ax - A) / max((float)N, 1.0f);
}

HOST_DEVICE inline float GetNearestGreaterPowerOfTwo(const float& x)
{
	return float( pow( 2, ceil( log(x) / log(2.0) ) ) );
}

HOST_DEVICE inline bool IsPowerOfTwo(const float f) {
	// source: http://cottonvibes.blogspot.com/2010/08/checking-if-float-is-power-of-2.html
	unsigned __int32& i = (unsigned __int32&)f;
	unsigned __int32  e = (i>>23) & 0xff;
	unsigned __int32  m =  i & 0x7fffff;
	return !m && e >= 127;
}

}
