BIN := $(shell basename $$(pwd))

MANSECTION := 1
MANPAGE := $(BIN).$(MANSECTION)

SRCS := $(wildcard *.cpp)
OBJS := $(subst .cpp,.o,$(SRCS))
DEPS := $(subst .cpp,.d,$(SRCS))

CXX ?= g++
PKG_CONFIG ?= pkg-config

PREFIX ?= /usr/local
BINDIR ?= $(PREFIX)/bin
DATADIR ?= $(PREFIX)/share
MANDIR ?= $(DATADIR)/man/man

RM := /bin/rm -f
MKDIR := /bin/mkdir -p
INSTALL := /usr/bin/install -c

CXXFLAGS := $(CXXFLAGS) -Wshadow -Wall -Wpedantic -Wextra -g -fno-strict-aliasing -std=c++17 -pthread
ifeq ($(DEBUG),1)
	CXXFLAGS += -D DEBUG -O0
else
	CXXFLAGS += -D NDEBUG -O3
endif

LDLIBS := -lm -lpthread

all: $(BIN)

$(BIN): $(OBJS) $(DEPS)
	$(CXX) $(OBJS) $(LDFLAGS) $(LDLIBS) -o $(BIN)

%.o: %.cpp %.d Makefile
	$(CXX) $(CXXFLAGS) -MMD -MP -MT $@ -MF $*.d -c $<

-include *.d

%.d: ;

.PHONY: clean install

clean:
	$(RM) $(OBJS) $(DEPS) $(BIN)

install: $(BIN)
	$(INSTALL) $(BIN) $(DESTDIR)$(BINDIR)
