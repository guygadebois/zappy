/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcouly <dcouly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/07 16:29:11 by dcouly            #+#    #+#             */
/*   Updated: 2014/06/26 11:10:53 by dcouly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# include "types.h"
# include "map.h"
# include "get_arg.h"

int		err_function(char *function);
int		err_malloc(void);

t_arg	*ft_get_arg(int argc, char **argv);
int 	ft_find_ret(char *str);
int		create_server(int port);
int		sv_loop(int sock, t_arg *arg);
int		sv_listen_fd(t_data *game, int *fdmax, t_fds *fds);
int		sv_read_from_client(t_data *game, int cs, fd_set *master);
int		sv_insert_trant(t_data *game, int cs, char buf[1024]);
t_trant	*sv_getclientbysock(t_data *game, int cs);
void	append_in_workbuf(t_data *game, t_trant *trant, char *buf, int rd_oct);
void	sv_send(t_data *game, int sock);
t_area	***ft_create_map(int x, int y, int nb_max);
void	sv_cmd_visu(t_data *game, char *buf, int rd_oct);
void	sv_send_visu(t_data *game);
void	sv_answer_cmd(t_data *game, t_trant *trant);
void	ft_move_forward(t_data *game, t_trant *trant, t_area ***map);
void	add_trant_map(t_area ***map, t_trant *trant);
void	ft_turn_right(t_trant *trant, t_data *game);
void	ft_turn_left(t_trant *trant, t_data *game);
void	ft_strstrcat(char cmd_out[BUF_VISU], char *cmd, int nb, ...);
void	sv_new_trant_to_visu(t_data *game, t_trant *trant);
void	ft_drop_obj(t_area ***map, t_trant *trant, char *obj, t_data *game);
void	ft_take_obj(t_area ***map, t_trant *trant, char *obj, t_data *game);
void	ft_get_inventory(t_trant *trant);
void	broadcast(t_data *game, char *msg, int sock);
int		sv_del_trant(t_data *data, int cs);
int		voir(t_data *data, t_trant *trant);
int		ft_sendall(int s, char *buf, int len);
void	sv_incantation(t_data *game, t_trant *trant);
void	ft_place_food(t_area ***map, int x, int y, int nb);
void	ft_place_deraumere(t_area ***map, int x, int y, int nb);
void	ft_place_sibur(t_area ***map, int x, int y, int nb);
void	ft_place_linemate(t_area ***map, int x, int y, int nb);
void	ft_place_phiras(t_area ***map, int x, int y, int nb);
void	ft_place_mendiane(t_area ***map, int x, int y, int nb);
void	ft_place_thystane(t_area ***map, int x, int y, int nb);
void	ft_kick(t_arg *game, t_area ***map, t_trant *trant);
void	ft_connect_nbr(t_arg *arg, t_list *trant, char *team, t_trant *tran);
int		sv_o_trant_init(t_trant **trant, int sock, char buf[1024], t_data *game);
void	ft_fork(t_data *game, t_trant *trant);

#endif
