//CLASSES------------------------------------------------------------------------------------------


class CustomMission: MissionServer
{	
	void SetRandomHealth( EntityAI itemEnt )
	{
		if ( itemEnt )
		{
			int rndHlt = Math.RandomInt( 55,100 );
			itemEnt.SetHealth( "", "", rndHlt );
		}
	}
	
	void SetPristine( EntityAI itemEnt )
	{ if ( itemEnt ) itemEnt.SetHealth( "", "", 100 ) }

	override PlayerBase CreateCharacter( PlayerIdentity identity, vector pos, ParamsReadContext ctx, string characterName )
	{
		Entity playerEnt;
		playerEnt = GetGame().CreatePlayer( identity, characterName, pos, 0, "NONE" );
		Class.CastTo( m_player, playerEnt );
		
		GetGame().SelectPlayer( identity, m_player );
		
		return m_player;
	}
	
	override void StartingEquipSetup( PlayerBase player, bool clothesChosen )
	{
		EntityAI itemTop;
		EntityAI itemEnt;
		ItemBase itemBs;
		float rand;
		
		itemTop = player.FindAttachmentBySlotName( "Body" );
		
		if ( itemTop )
		{
			itemEnt = itemTop.GetInventory().CreateInInventory( "Rag" );
			if ( Class.CastTo( itemBs, itemEnt ) ) itemBs.SetQuantity( 6 );
			SetPristine( itemEnt );
			
			itemEnt = itemTop.GetInventory().CreateInInventory( "RoadFlare" );
			SetPristine( itemEnt );
			
			itemEnt	= player.GetInventory().CreateInInventory( "Plum" );
			SetPristine( itemEnt );
		}
	}
};