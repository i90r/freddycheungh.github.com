var movement = {
	left	: 0,
	down	: 1,
	right	: 2,
	cw		: 3,
	ccw		: 4,
	drop	: 5
}

var keys = {
	space 	: 32,
	left	: 37,
	up		: 38,
	right	: 39,
	down	: 40
}

var data = {
	i : [[[0,1], [1,1], [2,1], [3,1]], [[2,0], [2,1], [2,2], [2,3]], [[0,2], [1,2], [2,2], [3,2]], [[1,0], [1,1], [1,2], [1,3]]],
	j : [[[0,0], [0,1], [1,1], [2,1]], [[2,0], [1,0], [1,1], [1,2]], [[2,2], [2,1], [1,1], [0,1]], [[0,2], [1,2], [1,1], [1,0]]],
	l : [[[2,0], [2,1], [1,1], [0,1]], [[2,2], [1,2], [1,1], [1,0]], [[0,2], [0,1], [1,1], [2,1]], [[0,0], [1,0], [1,1], [1,2]]],
	o : [[[1,0], [2,0], [1,1], [2,1]], [[1,0], [2,0], [1,1], [2,1]], [[1,0], [2,0], [1,1], [2,1]], [[1,0], [2,0], [1,1], [2,1]]],
	t : [[[1,0], [1,1], [0,1], [2,1]], [[2,1], [1,1], [1,0], [1,2]], [[1,2], [1,1], [2,1], [0,1]], [[0,1], [1,1], [1,2], [1,0]]],
	z : [[[0,0], [1,0], [1,1], [2,1]], [[2,0], [2,1], [1,1], [1,2]], [[2,2], [1,2], [1,1], [0,1]], [[0,2], [0,1], [1,1], [1,0]]],
	s : [[[2,0], [1,0], [1,1], [0,1]], [[2,2], [2,1], [1,1], [1,0]], [[0,2], [1,2], [1,1], [2,1]], [[0,0], [0,1], [1,1], [1,2]]]
}

var colors = {
	i : {inner : '#AACCFF', outer : '#336699'},
	j : {inner : '#AACCFF', outer : '#336699'},
	l : {inner : '#AACCFF', outer : '#336699'},
	o : {inner : '#AACCFF', outer : '#336699'},
	t : {inner : '#AACCFF', outer : '#336699'},
	z : {inner : '#AACCFF', outer : '#336699'},
	s : {inner : '#AACCFF', outer : '#336699'}
}

var elements = {
	board 	: document.getElementById('gfx-board'),
	stack 	: document.getElementById('gfx-stack'),
	shadow 	: document.getElementById('gfx-shadow'),
	piece 	: document.getElementById('gfx-piece')
}

var context = {
	board 	: elements.board.getContext('2d'),
	stack 	: elements.stack.getContext('2d'),
	shadow 	: elements.shadow.getContext('2d'),
	piece 	: elements.piece.getContext('2d')
}

var board = new function() {

	var data = [
		[0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
		[0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
		[0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
		[0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
		[0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
		[0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
		[0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
		[0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
		[0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
		[0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
		[0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
		[0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
		[0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
		[0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
		[0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
		[0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
		[0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
		[0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
		[0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
		[0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
	];

	var height = 20;
	var width = 10;

	this.add_piece = function() {
		for (var i = 0; i < 4; i++) {
			this.data[piece.getY(i)][piece.getX(i)] = piece.value;
		}
	};

	this.check_rows = function() {
	};

	this.draw = function() {
	};

	this.is_free_at = function(x, y) {
	};

	this.shift_down = function(count) {
		for (var r = height - 1; r >= 0; r--) {
			data[r] = (r - count < 0 ? [0, 0, 0, 0, 0, 0, 0, 0, 0, 0] : data[r - count]);
		}
	};

}

var piece = new function() {

	var d = undefined;
	var r = 0;
	var x = 0;
	var y = 0;

	this.value = 1;

	this.check = function(action) {
		var success = true;
		switch (action) {
			case movement.left:
				var temp_x = x - 1;
				for (var i = 0; i < 4; i++)
					if (!board.is_free_at(d[r][i][0] + temp_x, d[r][i][1] + y)) {
						success = false;
						break;
					}
				break;
			case movement.down:
				var temp_y = y + 1;
				for (var i = 0; i < 4; i++)
					if (!board.is_free_at(d[r][i][0] + x, d[r][i][1] + temp_y)) {
						success = false;
						break;
					}
				break;
			case movement.right:
				var temp_x = x + 1;
				for (var i = 0; i < 4; i++)
					if (!board.is_free_at(d[r][i][0] + temp_x, d[r][i][1] + y)) {
						success = false;
						break;
					}
				break;
			case movement.cw:
				var temp_r = (r == 3 ? 0 : r + 1);
				for (var i = 0; i < 4; i++)
					if (!board.is_free_at(d[temp_r][i][0] + x, d[temp_r][i][1] + y)) {
						success = false;
						break;
					}
				break;
			case movement.ccw:
				var temp_r = (r == 0 ? 3 : r - 1);
				for (var i = 0; i < 4; i++)
					if (!board.is_free_at(d[temp_r][i][0] + x, d[temp_r][i][1] + y)) {
						success = false;
						break;
					}
				break;
		}
		return success;
	};

	this.draw = function() {
	};

	this.draw_shadow = function() {
	};

	this.getX = function(index) {
		return d[r][index][0] + location[0];
	};

	this.getY = function(index) {
		return d[r][index][1] + location[1];
	};

	this.move = function(action) {
		switch (action) {
			case movement.left:
				location[0]--;
				break;
			case movement.down:
				location[1]++;
				break;
			case movement.right:
				location[0]++;
				break;
			case movement.cw:
				r = (r == 3 ? 0 : r + 1);
				break;
			case movement.ccw:
				r = (r == 0 ? 3 : r - 1);
				break;
			case movement.drop:
				// todo
				break;
		}
	};

	this.reset = function() {
		r = 0;
		x = 0;
		y = 0;
	};

	this.set = function(object) {
		d = object;
	};

}

var tetris = new function() {

	var active = {
		32 : false,
		37 : false,
		38 : false,
		39 : false,
		40 : false
	};

	var thread = undefined;

	this.start = function() {
	};

	this.place = function() {
	};

	this.update = function(action) {
		switch (action) {
			case movement.left:
				break;
			case movement.down:
				break;
			case movement.right:
				break;
			case movement.cw:
				break;
			case movement.ccw:
				break;
			case movement.drop:
				break;
		}
	};

	this.tick = function() {
		thread = setTimeout(tetris.tick, 1000);
	};

	this.key_down = function(event) {
		event = event || window.event;
		var code = event.which || event.keyCode;
		switch (code) {
			case keys.space:
				break;
			case keys.left:
				break;
			case keys.up:
				break;
			case keys.down:
				//clearTimeout
				this.update(movement.down);
				//setTimeout
				break;
			case keys.right:
				break;
		}
	};

	this.key_up = function(event) {
		event = event || window.event;
		var code = event.which || event.keyCode;
	};

}

window.addEventListener(
	'keydown',
	tetris.key_down,
	false
);

window.addEventListener(
	'keyup',
	tetris.key_up,
	false
);
