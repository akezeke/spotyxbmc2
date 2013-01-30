#!/bin/sh

API=../../../lib/libspotify/api.h

echo '#pragma once'
echo
echo '#include "DynamicDll.h"'
echo '#undef byte'
echo

sed -n -e 's/.*PUBLIC_API_H.*//'               \
       -e 's/[ \t]*\/\*.*\*\/.*//'             \
       -e 's/[ \t]*\/\/\/.*$//'                \
       -e '/[ \t]*\/\*/,/^[ \t]*\*\//{s/.*//}' \
       -e 's/^SP_LIBEXPORT.*//'                \
       -e '/^[ \t]*$/!p'                       \
       $API

echo
echo 'class DllLibspotifyInterface'
echo '{'
echo 'public:'
echo '    virtual ~DllLibspotifyInterface() {}'
echo

awk '/^[ \t]*SP_LIBEXPORT\(/ {
    printf "    virtual "

    match($0, /\([^\)]+\)/)
    printf substr($0, RSTART+1, RLENGTH-2) " "

    match($0, /[a-z_]+\(/)
    printf substr($0, RSTART, RLENGTH-1) "("

    match($0, /[a-z]\(.+\)/)
    c = split(substr($0, RSTART+2, RLENGTH-3), p, ", ")
    for(i = 1; i <= c; i++) {
        if(index(p[i], " ")) {
            if(i>1)
                printf ", "
            sub(/[a-z_]+$/, "", p[i])
        }
        printf p[i]
    }
    printf ") = 0;\n"
}' $API

echo '};'
echo
echo 'class DllLibspotify : public DllDynamic, DllLibspotifyInterface'
echo '{'
echo '    DECLARE_DLL_WRAPPER(DllLibspotify, "libspotify.so")'
echo

awk '/^[ \t]*SP_LIBEXPORT\(/ {
    printf "    DEFINE_METHOD"

    if(match($0, /\( *void *\) *;/))
        printf "0("
    else
        printf split($0, tmp, ",") "("

    match($0, /\([^\)]+\)/)
    printf substr($0, RSTART+1, RLENGTH-2) ", "

    match($0, /[a-z_]+\(/)
    printf substr($0, RSTART, RLENGTH-1)

    match($0, /[a-z]\(.+\)/)
    t = substr($0, RSTART+2, RLENGTH-3)

    if(t != "void") {
        printf  ", ("

        c = split(t, p, ", ")
        for(i = 1; i <= c; i++) {
            if(index(p[i], " ")) {
                if(i>1)
                    printf ", "

                if(match(p[i], /\[[^\]]*\]$/)) {
                    r = substr(p[i], RSTART)
                    p[i] = substr(p[i], 1, RSTART - 1)
                }
                else
                    r = ""

                sub(/[a-z_]+$/, "p" i r, p[i])
            }
            printf p[i]
        }
        printf ")"
    }

    printf ")\n"
}' $API

echo
echo '    BEGIN_METHOD_RESOLVE()'

sed -n 's|^SP_LIBEXPORT.* \([^(]\+\)(.*|    RESOLVE_METHOD(\1)|p' $API

echo '    END_METHOD_RESOLVE()'
echo '};'
