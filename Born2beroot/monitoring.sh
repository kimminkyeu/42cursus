#!/bin/bash


# ---[ 쉘 명령어 옵션1 ]----------------------------------------
# echo 후 줄바꿈을 하기 위해서... echo가 탈출 문자인 \ 를 만나면 
# 특수 문자로 처리하도록 하려면 -e 옵션을 주고 실행
# echo 매개 변수에 -n을 추가하면 원하는 대로 한 줄로 표현할 수 있다. 
# -- 실행 예시 --
# $ echo -n xxx: ; printf "mm" ---> (출력 결과 : xxx:mm)

# ---[ 쉘 명령어 옵션2 ]----------------------------------------
# ; - 앞의 명령어가 실패해도 다음 명령어가 실행
# && - 앞의 명령어가 성공했을 때 다음 명령어가 실행
# & - 앞의 명령어를 백그라운드로 돌리고 동시에 뒤의 명령어를 실행
# --------------------------------------------------------------


# --------------------------------------------------------------
# linux에서 cpu 정보 확인하는 방법 https://letitkang.tistory.com/50
# uname 명령어 = 시스템 정보를 -a 로 모두  출력
echo -en "#Architecture: "; uname -a


# 물리 cpu 개수             ^기호는 라인의 시작을 의미
# --------------------------------------------------------------
echo -en "#CPU physical : "; grep ^processor /proc/cpuinfo | wc -l


# 가상 cpu 개수       
# --------------------------------------------------------------
# (1) -c 는 일치 라인 출력   --> Q : 위랑 뭐가 다른거여??
echo -en "#vCPU : "; grep -c processor /proc/cpuinfo



# The current available RAM on your server and its utilization rate as a percentage.
# --------------------------------------------------------------
#  (1) free 명령어 : 리눅스 시스템에서 메모리의 전체적인 현황을 빠르게 살펴볼 수 있는 명령어이다
# -m -g -k -b 옵션 : 메가, 기가 단위 직접 지정
#		   -h 옵션 : 보기 좋게 단위은 단위로 자동 출력
# --------------------------------------------------------------
echo -en "#Memory Usage: "; free -m \
							| awk 'NR==2 {printf"%s/%sMB (%.2f%%)\n", $3, $2, $3/$2*100 }'



# The current available memory on your server and its utilization rate as a percentage.
# --------------------------------------------------------------
# (1) df 명령어 : disk free , 전체 디스크 여유공간 확인			
#		-h 옵션 : 사람이 보기 좋게 메가, 기가 단위로 디스크 공간 확인
# --------------------------------------------------------------
# (2) du 명령어 : disk usage , 특정 디렉토리를 기준으로 디스크 사용량을 확인
#		-h 옵션 : 똑같이 메가, 기가단위로 표현 
#		-s 옵션 : 서브디렉토리 출력하지 않고, 요약된 정보를 출력
#		예시	: sudo du -sh /home 
# --------------------------------------------------------------
#echo -en "#Disk Usage: "; df -m | awk '$NF=="/" {printf "%s", $3}'; \
#						  df -h | awk '$NF=="/" {printf "/%s (%s)\n", $2, $5}'
						# NF -> number of field. 비어있으면 마지막 필드(열) --> 최상단 디텍토리 출력 .	
						# 먼저 메가바이트로 앞자리를 출력하고, 뒤를 기가로 맞추기 위함

echo -en "#Disk Usage: "; df -h | awk '$NF=="/" {printf "%d/%s (%s)\n", $3, $2, $5}'
		


# The current utilization rate of your processors as a percentage.
# --------------------------------------------------------------
# (1) top 명령어 : 유닉스 계열의 시스템에서 프로세스 목록을 CPU 사용률이 높은 것부터 보여준다.
# (2) https://support.site24x7.com/portal/en/kb/articles/how-is-cpu-utilization-calculated-for-a-linux-server-monitor
# (3) https://sarc.io/index.php/forum/tips/3117-cpu 
#   * -b		: 배치모드 옵션 (인터랙션 가능모드가 아니라 출력 결과로 딱 나옴) 
# (참고)
# https://unix.stackexchange.com/questions/138484/what-does-batch-mode-mean-for-the-top-command
#   * -n		: top 실행 주기를 설정
# ex. -n1을 하면, top 실행 주기를 1회로 설정한다. (안그럼 화면이 바뀌(갱신))
#   * -p		: process ID 
# --------------------------------------------------------------
# 주의! -bn2 처럼 뒤에 숫자가 1이 아니면 화면 갱신 2회를 하고 끝나서 출력이 바로 안됨.
# 내가 그랩하는 id는 idle value, 즉 노는 cpu용량을 말한다. 
echo -en "#CPU load: "; top -bn1 \
					| grep "Cpu(s)" \
					| awk -F "," '{print 100 - $4 "%"}'
					# 구분자를 쉼표 기준으로 4번째 필드(id) 사용




# The date and time of the last reboot.
# --------------------------------------------------------------
# (1) https://m.blog.naver.com/PostView.naver?isHttpsRedirect=true&blogId=diceworld&logNo=220310435674 
# (2) https://www.thegeekstuff.com/2011/10/linux-reboot-date-and-time/
# last reboot 명령어 : 날짜가 숫자로 안나옴 (ex Mar)
#		   사용 예시 : last reboot | awk -F "  " 'NR==1 {print $4}'
#	   who -b 명령어 : 날짜가 숫자로 나옴 (ex 2011-...) --> 요구사항에 따라 이렇게 하기로 결정

echo -en "#Last boot: "; last reboot -F \
						| awk 'NR==1 {printf"%s-%s-%s %s\n", $9,$6,$7,$8}'

#echo -en "#Last boot: "; who -b  \
#						| awk '{print $3,$4}'



# Whether LVM is active or not.
# --------------------------------------------------------------
# 문제			:  awk를 쓰니 발견한 모든 레코드에 대해 출력해서, shell 자체 if문 사용함. 
# 참조 링크		: https://brownbears.tistory.com/221
# grep -q 옵션  : 출력하지 말것. (이거 안하면 싹다 출력함) 
echo -en "#LVM use: "; if (cat /etc/fstab | grep -q "/dev/mapper/";) \
						then echo "yes"; \
						else echo "no"; \
						fi


# The number of active connections.
# (1) netstat -at 명령어 : Listing only TCP (Transmission Control Protocol) port connections using netstat -at.
# -a : all / -t : tcp / -u : udp
# --------------------------------------------------------------
echo -en "#Connections TCP : "; netstat -at \
								| grep "ESTABLISHED" \
								| wc -l | tr '\n' ' ' && echo "ESTABLISHED"

# The number of users using the server.
# --------------------------------------------------------------
# https://www.computerhope.com/issues/ch001649.htm
echo -en "#User log: "; who | wc -l


# The IPv4 address of your server and its MAC (Media Access Control) address.
# https://opensource.com/article/18/5/how-find-ip-address-linux
# --------------------------------------------------------------
#echo -en "#Network: "; echo -n "IP " && ip route list \
#						| grep link | awk '{print $9}' \
#						| tr '\n' ' ' && echo -n "(" && ip link show \
#						| grep link/ether \
#						| awk '{print $2}' \
#						| tr '\n' ')' && printf "\n"


# hostname -I : ip 주소 출력용
# ip addr	  : mac 주소 출력용
echo -en "#Network: "; echo -n "IP " && hostname -I \
						| tr '\n' ' ' | tr -d ' ' && ip addr | grep 'link/ether' \
						| awk '{printf " (%s)\n", $2}'
	
# The number of commands executed with the sudo program.
# 내 sudo 파일 위치 : var/log/sudo/sudo_history 에 있음
# --------------------------------------------------------------
echo -en "#Sudo : "; cat /var/log/sudo/sudo_history \
					| grep COMMAND \
					| wc -l | tr '\n' ' ' && echo "cmd"
