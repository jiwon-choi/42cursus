# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jiwchoi <jiwchoi@student.42seoul.k>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/09 15:56:00 by jiwchoi           #+#    #+#              #
#    Updated: 2021/03/09 15:56:03 by jiwchoi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM	debian:buster
LABEL	maintainer="jiwchoi <jiwchoi@student.42seoul.kr>"

RUN		apt-get update && apt-get -y upgrade && apt-get install -y \
		nginx \
		openssl \
		vim \
		php7.3-fpm \
		mariadb-server \
		php-mysql \
		wget

COPY	./srcs/run.sh ./
COPY	./srcs/default ./tmp
COPY	./srcs/wp-config.php ./tmp
COPY	./srcs/config.inc.php ./tmp

EXPOSE	80 443

CMD		bash run.sh
