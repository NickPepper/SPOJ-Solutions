%% Erlang solution to Life, the Universe, and Everything (Problem code: TEST)

-module(test).
-export([main/0]).

main() ->
    loop().
loop() ->
    case io:fread( "", "~d" ) of
        eof ->
            done;
        {ok, X} ->
            [Y] = X,
            if
                Y == 42 ->
                    done;
                true ->
                    io:fwrite( "~B\n", X ),
                    loop()
            end
    end.
