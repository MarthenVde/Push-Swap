# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    test.sh                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvan-d <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/20 08:42:33 by marvan-d          #+#    #+#              #
#    Updated: 2019/08/20 12:21:55 by marvan-d         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
#!/bin/bash

ARG=`ruby -e "puts (0..22).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./checker -c $ARG