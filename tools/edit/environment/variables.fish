set here "$(realpath -s "$(status dirname)")"

set edit_root "$(realpath -s $here/..)"

echo '# To undo, run:'

if set -qx VIS_PATH
  echo -- set VIS_PATH "$(string escape "$VIS_PATH")"
else
  echo -- set -u VIS_PATH
end

set -x VIS_PATH $edit_root

set path $edit_root/path

if set -qx PATH
	if not test $path = $PATH[1]
	  echo -- set PATH "$(string escape "$PATH[2..]")"
	  set PATH $path $PATH
	end
else
	echo -- set -u PATH
end
