/*
 * \brief  Genode WM a minimalistic tiling window manager
 * \author Pirmin Duss
 * \date   2017-06-24
 */

/*
 * Copyright (C) 2016 Genode Labs GmbH
 *
 * This file is part of the Genode OS framework, which is distributed
 * under the terms of the GNU General Public License version 2.
 */

/* Genode includes */
#include <timer_session/connection.h>
#include <rom_session/rom_session.h>
#include <os/signal_rpc_dispatcher.h>
#include <os/session_policy.h>


namespace Genode_wm {

	using namespace Genode;

	class Session_component;
	class Root;
	struct Main;
}


class Genode_wm::Session_component :
	public Genode::Rpc_object<Genode::Rom_session>
{
	private:

		Genode::Env &_env;

	public:

		Session_component(Genode::Env  &env) :
			_env(env),
		{
		}

		~Session_component()
		{
		}
};


class Genode_wm::Root : public Genode::Root_component<Session_component>
{
	private:

		Genode::Env                    &_env;
		Genode::Attached_rom_dataspace  _config_rom{_env, "config"};

	protected:

		Session_component *_create_session(const char *args) override
		{
			Session_component *session;
			return session;
		}

		void _destroy_session(Session_component *session) override
		{
			Genode::destroy(md_alloc(), session);
		}

	public:

		Root(Genode::Env &env)
		:
			Genode::Root_component<Session_component>(&env.ep().rpc_ep(), &md_alloc),
			_env(env)
		{
			env.parent().announce(env.ep().manage(*this));
		}
};


void Component::construct(Genode::Env &env)
{
  static Genode::Heap heap{env.ram(), env.rm()};
	static Genode_wm::Root root{env, heap};
}

