%% Solution for FCTRL2 problem (Small factorials)
-module(small_factorials). 
-export([main/0]). 

main() -> 
    {ok, [No_of_cases]} = io:fread( "", "~d" ), 
    loop(No_of_cases). 

loop(0) ->
    %%halt(1).
    done;
loop(No_of_cases) -> 
    {ok, [Number]} = io:fread("", "~d"), 
    ResultFactorial = find_factorial( Number, 1 ), 
    io:format( "~p~n", [ResultFactorial] ), 
    loop( No_of_cases - 1 ).

find_factorial( 0, Product ) -> 
    Product; 
find_factorial( Number, Product ) -> 
    find_factorial( Number-1, Product * Number ). 

