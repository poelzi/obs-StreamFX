// FFMPEG Video Encoder Integration for OBS Studio
// Copyright (c) 2019 Michael Fabian Dirks <info@xaymar.com>
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#pragma once
#include "common.hpp"

// Codec: H264
#define S_CODEC_H264 "Codec.H264"
#define S_CODEC_H264_PROFILE "Codec.H264.Profile"
#define S_CODEC_H264_LEVEL "Codec.H264.Level"

namespace streamfx::encoder::codec::h264 {
	enum class profile {
		CONSTRAINED_BASELINE,
		BASELINE,
		MAIN,
		HIGH,
		HIGH444_PREDICTIVE,
		UNKNOWN = -1,
	};

	enum class level {
		L1_0 = 10,
		L1_0b,
		L1_1,
		L1_2,
		L1_3,
		L2_0 = 20,
		L2_1,
		L2_2,
		L3_0 = 30,
		L3_1,
		L3_2,
		L4_0 = 40,
		L4_1,
		L4_2,
		L5_0 = 50,
		L5_1,
		L5_2,
		L6_0 = 60,
		L6_1,
		L6_2,
		UNKNOWN = -1,
	};

	// See ITU-T H.264
	enum class nal_unit_type : uint8_t {
		UNSPECIFIED                          = 0,
		CODED_SLICE_NONIDR                   = 1,
		CODED_SLICE_DATA_PARTITION_A         = 2,
		CODED_SLICE_DATA_PARTITION_B         = 3,
		CODED_SLICE_DATA_PARTITION_C         = 4,
		CODED_SLICE_IDR                      = 5,
		SUPPLEMENTAL_ENHANCEMENT_INFORMATION = 6,
		SEQUENCE_PARAMETER_SET               = 7,
		PICTURE_PARAMETER_SET                = 8,
		ACCESS_UNIT_DELIMITER                = 9,
		END_OF_SEQUENCE                      = 10,
		END_OF_STREAM                        = 11,
		FILLER_DATA                          = 12,
		SEQUENCE_PARAMETER_SET_EXTENSION     = 13,
		PREFIX_NAL_UNIT                      = 14,
		SUBSET_SEQUENCE_PARAMETER_SET        = 15,
		DEPTH_PARAMETER_SET                  = 16,
		CODED_SLICE_AUXILIARY_PICTURE        = 19,
		CODED_SLICE_EXTENSION                = 20,
		CODED_SLICE_EXTENSION_DEPTH_VIEW     = 21,
	};

	/** Search for the closest NAL unit.
	 *
	 * \param ptr Beginning of the search range.
	 * \param endptr End of the search range (exclusive).
	 * 
	 * \return A valid pointer if a NAL was found, otherwise \ref nullptr.
	 */
	uint8_t* find_closest_nal(uint8_t* ptr, uint8_t* endptr, size_t& size);

	uint32_t get_packet_reference_count(uint8_t* ptr, uint8_t* endptr);

} // namespace streamfx::encoder::codec::h264
