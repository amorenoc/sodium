#ifndef _SODIUM_CONFIG_H_
#define _SODIUM_CONFIG_H_

#if defined(__MSP430__)
#define SODIUM_NO_CXX11
#define SODIUM_NO_EXCEPTIONS
#define SODIUM_SINGLE_THREADED
#endif

#if defined(__MSP430__)
/*
#define SODIUM_STRONG_BITS 1
#define SODIUM_EVENT_BITS  6
#define SODIUM_NODE_BITS   6
#define SODIUM_CONSERVE_MEMORY
*/
#elif __WORDSIZE == 32
#define SODIUM_STRONG_BITS 1
#define SODIUM_EVENT_BITS  14
#define SODIUM_NODE_BITS   14
#define SODIUM_CONSERVE_MEMORY
#elif __WORDSIZE == 64
#define SODIUM_STRONG_BITS 1
#define SODIUM_EVENT_BITS  31
#define SODIUM_NODE_BITS   31
#define SODIUM_CONSERVE_MEMORY
#endif

#if defined(SODIUM_NO_CXX11)
#define EQ_DEF_PART
#define SODIUM_SHARED_PTR   boost::shared_ptr
#define SODIUM_MAKE_SHARED  boost::make_shared
#define SODIUM_WEAK_PTR     boost::weak_ptr
#define SODIUM_TUPLE        boost::tuple
#define SODIUM_MAKE_TUPLE   boost::make_tuple
#define SODIUM_TUPLE_GET    boost::get
#define SODIUM_FORWARD_LIST std::list
#else
#define EQ_DEF_PART = sodium::def_part
#define SODIUM_SHARED_PTR   std::shared_ptr
#define SODIUM_MAKE_SHARED  std::make_shared
#define SODIUM_WEAK_PTR     std::weak_ptr
#define SODIUM_TUPLE        std::tuple
#define SODIUM_MAKE_TUPLE   std::make_tuple
#define SODIUM_TUPLE_GET    std::get
#define SODIUM_FORWARD_LIST std::forward_list
#endif

#endif
