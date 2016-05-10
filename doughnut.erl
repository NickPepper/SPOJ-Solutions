%% this is a DOUGHNUT problem solution for Sphere Online Judge

-module(doughnut).
-export([main/0]).

main() ->
    {ok,[Count]} = io:fread("", "~d"),
    loop(Count).

loop(Count) ->
    case io:fread( "", "~d ~d ~d" ) of
	{ok,[C,K,W]} ->
	    if
		C * W =< K ->
		    io:fwrite("~s~n", [yes]);
		true -> 
		    io:fwrite("~s~n", [no])
	    end,
	    
	    if
		Count > 1 ->
		    loop(Count-1);
		true ->
		    done
	    end;

	eof ->
	    done
    end.
