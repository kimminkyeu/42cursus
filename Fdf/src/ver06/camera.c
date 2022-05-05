#include "../include/camera.h"

extern t_mat4x4     multiply_matrix4x4(t_mat4x4 m1, t_mat4x4 m2);

t_mat4x4 translate_3d(float _x, float _y, float _z)
{
	static t_mat4x4  mat;

	mat.m[0][0] = 1.0f;
	mat.m[1][1] = 1.0f;
	mat.m[2][2] = 1.0f;
	mat.m[3][3] = 1.0f;
	mat.m[0][3] = _x;
	mat.m[1][3] = _y;
	mat.m[2][3] = _z;
	return (mat);
}

t_mat4x4 rotate_z_3d(float _degree)
{
	static t_mat4x4  mat;

	mat.m[0][0] = cosf(get_radian(_degree));
	mat.m[0][1] = -sinf(get_radian(_degree));
	mat.m[1][0] = sinf(get_radian(_degree));
	mat.m[1][1] = cosf(get_radian(_degree));
	mat.m[2][2] = 1.0f;
	mat.m[3][3] = 1.0f;
	return (mat);
}

t_mat4x4 rotate_x_3d(float _degree)
{
	static t_mat4x4  mat;

	mat.m[0][0] = 1.0f;
	mat.m[1][1] = cosf(get_radian(_degree));
	mat.m[1][2] = -sinf(get_radian(_degree));
	mat.m[2][1] = sinf(get_radian(_degree));
	mat.m[2][2] = cosf(get_radian(_degree));
	mat.m[3][3] = 1.0f;
	return (mat);
}

t_mat4x4 set_z_unit(float _z_unit)
{
	static t_mat4x4 mat;

	mat.m[0][0] = 1.0f;
	mat.m[1][1] = 1.0f;
	mat.m[2][2] = _z_unit;
	mat.m[3][3] = 1.0f;
	return (mat);
}

t_mat4x4 rotate_y_3d(float _degree)
{
	static t_mat4x4  mat;

	mat.m[0][0] = cosf(get_radian(_degree));
	mat.m[0][2] = -sinf(get_radian(_degree));
	mat.m[1][1] = 1.0f;
	mat.m[2][0] = sinf(get_radian(_degree));
	mat.m[2][2] = cosf(get_radian(_degree));
	mat.m[3][3] = 1.0f;
	return (mat);
}

/* scale from (0.0) */
t_mat4x4 scale_origin_3d(float _scale_rate)
{
	static t_mat4x4 mat;

	mat.m[0][0] = _scale_rate;
	mat.m[1][1] = _scale_rate;
	mat.m[2][2] = _scale_rate;
	mat.m[3][3] = 1.0f;
	return (mat);
}

/* sclae from (x, y, z) */
t_mat4x4 scale_point_3d(float _x, float _y, float _z, float _scale_rate)
{
	static t_mat4x4 mat;

	mat = multiply_matrix4x4(scale_origin_3d(_scale_rate), translate_3d(-_x, -_y, -_z));
	mat = multiply_matrix4x4(translate_3d(_x, _y, _z), mat);
	return (mat);
}

t_mat4x4 project_nothing(void)
{
	static t_mat4x4 mat;

	mat.m[0][0] = 1.0f;
	mat.m[1][1] = 1.0f;
	mat.m[2][2] = 1.0f;
	mat.m[3][3] = 1.0f;
	return (mat);
}

t_mat4x4	fit_to_viewport(t_mlx *fdf)
{
	static t_mat4x4 mat;
	float			offset_x;
	float			offset_y;

	offset_x = (WIN_WIDTH - fdf->map_info.max_x) / 2;
	offset_y = (WIN_HEIGHT - fdf->map_info.max_y) / 2;

	mat = translate_3d(offset_x, offset_y, 0);
	return (mat);
}

t_mat4x4	camera_tranform(t_mlx *fdf)
{
	static t_mat4x4 mat;

	mat = set_z_unit(fdf->camera.z_unit);
	mat = multiply_matrix4x4(rotate_x_3d(fdf->camera.angle.x), mat);
	mat = multiply_matrix4x4(rotate_y_3d(fdf->camera.angle.y), mat);
	mat = multiply_matrix4x4(rotate_z_3d(fdf->camera.angle.z), mat);
	mat = multiply_matrix4x4(translate_3d(fdf->camera.pos.x, fdf->camera.pos.y, fdf->camera.pos.z), mat);
	mat = multiply_matrix4x4(scale_point_3d(fdf->camera.pos.x, fdf->camera.pos.y, fdf->camera.pos.z, fdf->camera.zoom_rate), mat);
	return (mat);
}

t_mat4x4	orthographic_projection(void)
{
	static  t_mat4x4 mat;

	mat.m[0][0] = cosf(get_radian(30.0f));
	mat.m[0][1] = -cosf(get_radian(30.0f));
	mat.m[1][0] = sinf(get_radian(30.0f));
	mat.m[1][1] = sinf(get_radian(30.0f));
	mat.m[1][2] = -1.0f;
	return (mat);
}

void    camera_init(t_mlx *fdf)
{
	fdf->camera.zoom_rate = 10.0f;
	fdf->camera.projection_matrix = project_nothing();
	fdf->camera.angle.x = 0.0f;
	fdf->camera.angle.y = 0.0f;
	fdf->camera.angle.z = 0.0f;
	fdf->camera.pos.x = 0.0f;
	fdf->camera.pos.y = 0.0f;
	fdf->camera.pos.z = 0.0f;
	fdf->camera.z_unit = 0.1f;
	fdf->camera.move_speed = 20.0f;
	fdf->camera.rotation_speed = 10.0f;
	fdf->camera.zoom_speed = 1.0f;
}
