all: test_sodium memory/release-sink-machinery memory/switch-memory

CPPFLAGS=-I.. -g
ifeq ($(NO_CXX11),)
CPPFLAGS+=--std=c++11
else
CPPFLAGS+=-DSODIUM_NO_CXX11
endif

OBJECT_FILES= \
    ../sodium/lock_pool.o \
    ../sodium/light_ptr.o \
    ../sodium/transaction.o \
    ../sodium/sodium.o

SODIUM_HEADERS=../sodium/sodium.h ../sodium/transaction.h ../sodium/light_ptr.h ../sodium/count_set.h ../sodium/lock_pool.h

../sodium/light_ptr.o:           ../sodium/light_ptr.h ../sodium/lock_pool.h
../sodium/transaction.o:         ../sodium/transaction.h ../sodium/lock_pool.h ../sodium/light_ptr.h ../sodium/count_set.h
../sodium/sodium.o:              $(SODIUM_HEADERS)
test_sodium.o:                   $(SODIUM_HEADERS) test_sodium.h
memory/release-sink-machinery.o: $(SODIUM_HEADERS)
memory/switch-memory.o:          $(SODIUM_HEADERS)

test_sodium: $(OBJECT_FILES) test_sodium.o
	$(CXX) -o $@ $(OBJECT_FILES) test_sodium.o -lpthread -lcppunit

memory/release-sink-machinery: $(OBJECT_FILES) memory/release-sink-machinery.o
	$(CXX) -o $@ $(OBJECT_FILES) memory/release-sink-machinery.o -lpthread

memory/switch-memory: $(OBJECT_FILES) memory/switch-memory.o
	$(CXX) -o $@ $(OBJECT_FILES) memory/switch-memory.o -lpthread

clean:
	rm -f $(OBJECT_FILES) \
            test_sodium test_sodium.o \
            memory/release-sink-machinery memory/release-sink-machinery.o
