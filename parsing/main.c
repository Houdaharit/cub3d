/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakam <ahakam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 16:47:26 by ahakam            #+#    #+#             */
/*   Updated: 2023/01/12 23:32:05 by hharit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int main(int argc, char **argv)
{
    t_data map;
    if (argc == 2)
    {
        valid_map(argv[1], &map);
        storecolores(&map);
    }
        
    else
        printf("please enter a valid map only !\n");
    int i = 0;
    // while(map.Carr[i])
    // {
    //      printf("%d\n",map.Farr[i]);
    //      printf("|%d|\n",map.Carr[i]);
    //      i++;
    // }
   printf("%d\n",map.xPposition);
   printf("%d\n",map.yPposition);
   printf("%c\n", map.map[map.xPposition][map.yPposition]);
    // while(map.map[i])
    // {
    //     printf("%s\n",map.map[i]);
    //     i++;
    // }
    // printf("%s\n",map.floor[1]);
    // printf("%s\n",map.ceilling[1]);
    // printf("%s\n",map.south[1]);
    // printf("%s\n",map.west[1]);
    // printf("%s\n",map.east[1]);
    // printf("%s\n",map.north[1]);
    // while (1)
    // {
    //     /* code */
    // };
}
