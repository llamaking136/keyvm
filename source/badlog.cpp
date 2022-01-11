//
// badlog.cpp
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


#include <badlog.hpp>

char* gettime() {
	time_t now = time(0);
	char* dt = ctime(&now);
	return strtok(dt, "\n");
}

LogLevelConfig find_level_by_name(LogLevel level, LogLevelConfig configs[]) {
	for (int i = 0; i < 5; i++) { // This is such a bad idea XXX XXX XXX FIXME
		if (configs[i].level == level) {
			return configs[i];
		}
	}

	return LogLevelConfig{ LogLevel::Null, "", "" };
}

void Logger::setup() {
	this->defaultLevel = LogLevelConfig{ LogLevel::Info, "INFO", "\33[1;39m" };
	this->configs[0] = LogLevelConfig{ LogLevel::Fatal, "FATAL", "\33[1;41;39m"};
	this->configs[1] = LogLevelConfig{ LogLevel::Error, "ERROR", "\33[1;31m"};
	this->configs[2] = LogLevelConfig{ LogLevel::Warning, "WARNING", "\33[1;35m"};
	this->configs[3] = LogLevelConfig{ LogLevel::Info, "INFO", "\33[1;39m"};
	this->configs[4] = LogLevelConfig{ LogLevel::Debug, "DEBUG", "\33[1;34m"};

	this->log("Logger started");
}

Logger::Logger() {
	this->useStd = true;
	this->setup();
}

Logger::Logger(std::string filename) {
	this->useStd = false;
	this->outStream = std::ofstream(filename, std::ofstream::app);
	this->setup();
}

Logger::~Logger() {
	this->log("Logger stopping");
	if (!this->useStd) {
		this->outStream.close();
	}
}

void Logger::log(std::string msg) {
	if (this->useStd) {
		std::cout << "[" << gettime() << "] " << (this->useStd ? this->defaultLevel.color : "") << this->defaultLevel.name << ": " << msg << (this->useStd ? "\33[0m\n" : "\n");
	} else {
		this->outStream << "[" << gettime() << "] " << (this->useStd ? this->defaultLevel.color : "") << this->defaultLevel.name << ": " << msg << (this->useStd ? "\33[0m\n" : "\n");
	}
}

void Logger::log(LogLevel current_level, std::string msg) {
	LogLevelConfig level = find_level_by_name(current_level, this->configs);
	if (level.level == LogLevel::Null) {
		abort();
	}
	if (this->useStd) {
		std::cout << "[" << gettime() << "] " << (this->useStd ? level.color : "") << level.name << ": " << msg << (this->useStd ? "\33[0m\n" : "\n");
	} else {
		this->outStream << "[" << gettime() << "] " << (this->useStd ? level.color : "") << level.name << ": " << msg << (this->useStd ? "\33[0m\n" : "\n");
	}
}
