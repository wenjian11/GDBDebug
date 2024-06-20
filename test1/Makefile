CXX := g++

CXXFLAGS := -g -Wall -std=c++11

SRCS := $(wildcard *.cpp)

OBJS := $(patsubst %.cpp, %.o, $(SRCS))

TARGET := test1

all: $(TARGET)

# $@：表示规则中的目标文件的名字。在目标规则中，它代表了冒号前面的目标文件的名字。例如，在规则 $(TARGET): $(OBJS) 中，$@ 就代表 $(TARGET) 的值。
# $^：表示规则中的所有依赖文件的名字列表（以空格分隔）。在目标规则中，它代表了冒号后面的所有依赖文件。例如，在规则 $(TARGET): $(OBJS) 中，$^ 就代表 $(OBJS) 的值，也就是所有对象文件的名字。

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET) $(OBJS)

.PHONY: all clean