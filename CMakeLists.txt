cmake_minimum_required(VERSION 3.6)
project(Data_Structure)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        array_peaks/array_peaks/main.c
        BiTree/BiTree/main.c
        Febi_and_arithmeticByStack/Febi_and_arithmeticByStack/Febi_and_arithmeticByStack/main.c
        hashMap/HashMap.cpp
        hashMap/HashTable.h
        LinkList/LinkList/LinkList/main.c
        ListUnion/list_union/list_union/main.c
        ListUnion/main.c
        QueueWork/QueueWork/QueueWork/main.c
        sort_compare/sort_compare/sort_compare/main.c
        StackWork/StackWork/StackWork/main.c
        stringCheck/stringCheck/stringCheck/main.c
        TheMaxChild_String/TheMaxChild_String/main.c
        word_frequency_statistic/word_frequency_statistic/word_frequency_statistic/main.c
        testFile.c)

add_executable(Data_Structure ${SOURCE_FILES})