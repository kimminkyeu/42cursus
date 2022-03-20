/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyeki <minkyeki@42SEOUL.KR>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 19:26:04 by minkyeki          #+#    #+#             */
/*   Updated: 2022/03/15 16:55:19 by minkyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdint.h>  // TODO : for SIZE_MAX
// #include <errno.h>	// TODO : (공부 필요!) for errno setting (see menual of headers)
/** TODO : The UNIX 98 standard requires malloc(), calloc(), and realloc() to set errno to ENOMEM upon failure. */
// 상단 출처 :https://linux.die.net/man/3/calloc 

/** The  calloc() function allocates memory for an array of nmemb elements */
/**        of size bytes each and returns a pointer to the allocated memory.  The */
/**        memory  is  set to zero.  If nmemb or size is 0, then calloc() returns */
/**        either NULL, or a unique pointer value that can later be  successfully */
/**        passed  to  free().  */
// If the multiplication of nmemb and size would 
// result in integer overflow, then calloc() returns  an  error.

void	*ft_calloc(size_t nmemb, size_t size)
{
	// TODO: (1) malloc 자료형은 뭐로 해야 하지?
	//		 (2) integer overflow를 어떻게 감지하지? (TODO :이 부분 공부할것!)
	//		 답변 : https://stackoverflow.com/questions/199333/how-do-i-detect-unsigned-integer-multiply-overflow
	//		 (3) 만약 사용자가 size_t에 -1을 넣으면 우쨰하지? 이걸 막아야 하나?
	//		 -> 아 근데 -1을 넣으면 size_t max가 되서 overflow에 걸리네!
	//		 (4) calloc은 error시 errno를 사용해서 오류를 전송한다? 이 부분 중요해 보이는데?
	size_t	total_size;
	char	*tmp;
	// TODO : A pointer to the start of the allocated memory, or NULL if an error occurred (errno is set).
	// 메모리 할당에 실패하거나 요청된 메모리의 양이 _HEAP_MAXREQ를 초과하는 경우 malloc는 errno를 ENOMEM으로 설정합니다. (출처 : Microsoft docs -> malloc)
	// https://docs.microsoft.com/ko-kr/cpp/c-runtime-library/errno-constants?view=msvc-170
	// TODO : (1) 오버 플로우 등의 핸들링 함수 별로도 빼기
	// TODO : (2) errno 에 대해 알아보기
	// TODO : (3) size_t가 음수가 들어올 때 아래 경우에 걸리는지 체크. 
	if (nmemb > SIZE_MAX / size)
		return (NULL);
	total_size = nmemb * size;
	if (total_size == 0)
		return (NULL);
	tmp = (char *)malloc(total_size); // 모든 1byte들을 0으로 초기화하려면 char써야함
	if (!tmp)
		return (NULL);
	while (total_size > 0)
	{
		tmp[total_size - 1] = 0;
		--total_size;
	}
	return ((void *)tmp);
}
