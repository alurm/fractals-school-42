require('vis')

vis.events.subscribe(vis.events.INIT, function()
  -- Global configuration.
  vis:command('set theme default-16')
  vis:command('set autoindent')
  vis:command('set tabwidth 4')
  vis:command('set et!')
end)

vis.events.subscribe(vis.events.WIN_OPEN, function()
  -- Per window configuration.
  -- Example: vis:command('set number')
  vis:command('set et!')
  vis:command('set cc 81')
end)
