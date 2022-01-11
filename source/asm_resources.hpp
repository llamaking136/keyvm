//
// asm_resources.hpp
//
// created at 26/09/2021 20:49:13
// written by llamaking136
//

// MIT License
//     
// Copyright (c) 2021 llamaking136
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


#if !defined(ASM_RESOURCES_HPP)
#define ASM_RESOURCES_HPP

namespace ASM {
	enum ASM_Symbols {
		MOV = 0x01,
		
		ADD = 0x02,
		SUB = 0x03,
		MUL = 0x04,
		DIV = 0x05,

		CALL = 0x06,

		CMP = 0x07,

		PUSHARG = 0x08,

		AND = 0x09,
		OR = 0x0A,
		XOR = 0x0B,
		NOT = 0x0C,

		INC = 0x0D,
		DEC = 0x0E,

		NOP = 0x0F,

		SHL = 0x10,
		SHR = 0x11,

		POPARG = 0x12,
		POPARGS = 0x13,

		PUSH = 0x14,
		POP = 0x15,

		JZ = 0x16,
		JNZ = 0x17,
		JS = 0x18,
		JNS = 0x19,
		JO = 0x1A,
		JNO = 0x1B,
		JC = 0x1C,
		JNC = 0x1D,
		JB = 0x1E,
		JBE = 0x1F,
		JAE = 0x20,
		JA = 0x21,
		JL = 0x22,
		JLE = 0x23,
		JGE = 0x24,
		JG = 0x25,

		HLT = 0xFF
	};

	enum ASM_Registers {
		R0,
		R1,
		R2,
		R3,
		R4,
		R5,
		R6,
		R7,
		R8,
		R9,
		R10,
		R11,
		R12,
		R13,
		R14,
		R15
	};
}

#endif // ASM_RESOURCES_HPP
