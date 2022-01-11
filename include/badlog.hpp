//
// badlog.hpp
//
// created at 17/12/2021 20:56:06
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


#if !defined(BADLOG_HPP)
#define BADLOG_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <string.h>

// idfk how this works, good luck

enum LogLevel {
	Fatal,
	Error,
	Warning,
	Info,
	Debug,
	Null
};

struct LogLevelConfig {
	LogLevel level;
	std::string name;
	std::string color;
};

class Logger {
	private:
		bool useStd;
		std::ofstream outStream;
		LogLevelConfig defaultLevel;
		LogLevelConfig configs[5];
		std::string outfilename;
		void setup();

	public:
		 Logger();
		 Logger(std::string);
		~Logger();
		// void defaultLevel(LogLevel);
		void log(std::string);
		void log(LogLevel, std::string);
};

#endif // BADLOG_HPP
