#!/bin/bash
set -e


map="{\"백준\": \"b\", \"프로그래머스\": \"p\", \"leetcode\": \"lc\", \"etc\": \"e\"}"


ls -d ./solving/*/ | grep -v '.out.*'  | while read line
do
    # echo $line | sed -e 's/.\/solving\///'
    origin="${line}main.cpp"
    q_info=$(grep "//" $origin | head -n 1 | sed -e 's/\/\///')

    read -ra q_info <<< "$q_info" 

    q_type=${q_info[0]}
    q_id=${q_info[1]}
    q_name=${q_info[2]}

    if [ "$q_type" == "etc" ]; then
        q_id=""
        q_name=${q_info[1]}
    fi

    if [ "$q_type" == "" ] || [[ "$q_type" != "etc" && "$q_id" == "" ]]; then continue; fi

    q_type_id=$(echo $map | jq '.["'$q_type'"] // ""' --raw-output)

    for ((i = 3; ${#q_info[@]} > 3 && i < ${#q_info[@]}; i++)); do
        q_name="${q_name}${q_info[$i]}"
    done

    target="./${q_type}/${q_type_id}${q_id}_${q_name}.cpp"

    if [ -f "$target" ]; then
        regex="[_][0-9]+(.cpp)$"
        file_index=2
        target="./${q_type}/${q_type_id}${q_id}_${q_name}_${file_index}.cpp"
        while [ -f "$target" ]
        do
            file_index="$((file_index + 1))"
            target="./${q_type}/${q_type_id}${q_id}_${q_name}_${file_index}.cpp"
        done
    fi

    mv $origin $target
    if [ -f "$target" ]; then
        rm -r $line
    fi
done