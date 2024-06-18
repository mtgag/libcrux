use libcrux_ml_kem::mlkem768;

#[test]
fn kyber768() {
    let key_pair = mlkem768::generate_key_pair(hex::decode("7c9935a0b07694aa0c6d10e4db6b1add2fd81a25ccb148032dcd739936737f2d8626ed79d451140800e03b59b956f8210e556067407d13dc90fa9e8b872bfb8f").unwrap().try_into().unwrap());

    let public_key = key_pair.pk();
    let secret_key = key_pair.sk();

    assert_eq!( 
        public_key.as_ref(),
        hex::decode("A72C2D9C843EE9F8313ECC7F86D6294D59159D9A879A542E260922ADF999051CC45200C9FFDB60449C49465979272367C083A7D6267A3ED7A7FD47957C219327F7CA73A4007E1627F00B11CC80573C15AEE6640FB8562DFA6B240CA0AD351AC4AC155B96C14C8AB13DD262CDFD51C4BB5572FD616553D17BDD430ACBEA3E95F0B698D66990AB51E5D03783A8B3D278A5720454CF9695CFDCA08485BA099C51CD92A7EA7587C1D15C28E609A81852601B0604010679AA482D51261EC36E36B8719676217FD74C54786488F4B4969C05A8BA27CA3A77CCE73B965923CA554E422B9B61F4754641608AC16C9B8587A32C1C5DD788F88B36B717A46965635DEB67F45B129B99070909C93EB80B42C2B3F3F70343A7CF37E8520E7BCFC416ACA4F18C7981262BA2BFC756AE03278F0EC66DC2057696824BA6769865A601D7148EF6F54E5AF5686AA2906F994CE38A5E0B938F239007003022C03392DF3401B1E4A3A7EBC6161449F73374C8B0140369343D9295FDF511845C4A46EBAAB6CA5492F6800B98C0CC803653A4B1D6E6AAED1932BACC5FEFAA818BA502859BA5494C5F5402C8536A9C4C1888150617F80098F6B2A99C39BC5DC7CF3B5900A21329AB59053ABAA64ED163E859A8B3B3CA3359B750CCC3E710C7AC43C8191CB5D68870C06391C0CB8AEC72B897AC6BE7FBAACC676ED66314C83630E89448C88A1DF04ACEB23ABF2E409EF333C622289C18A2134E650C45257E47475FA33AA537A5A8F7680214716C50D470E3284963CA64F54677AEC54B5272162BF52BC8142E1D4183FC017454A6B5A496831759064024745978CBD51A6CEDC8955DE4CC6D363670A47466E82BE5C23603A17BF22ACDB7CC984AF08C87E14E27753CF587A8EC3447E62C649E887A67C36C9CE98721B697213275646B194F36758673A8ED11284455AFC7A8529F69C97A3C2D7B8C636C0BA55614B768E624E712930F776169B01715725351BC74B47395ED52B25A1313C95164814C34C979CBDFAB85954662CAB485E75087A98CC74BB82CA2D1B5BF2803238480638C40E90B43C7460E7AA917F010151FAB1169987B372ABB59271F7006C24E60236B84B9DDD600623704254617FB498D89E58B0368BCB2103E79353EB587860C1422E476162E425BC2381DB82C6592737E1DD602864B0167A71EC1F223305C02FE25052AF2B3B5A55A0D7A2022D9A798DC0C5874A98702AAF4054C5D80338A5248B5B7BD09C53B5E2A084B047D277A861B1A73BB51488DE04EF573C85230A0470B73175C9FA50594F66A5F50B4150054C93B68186F8B5CBC49316C8548A642B2B36A1D454C7489AC33B2D2CE6668096782A2C1E0866D21A65E16B585E7AF8618BDF3184C1986878508917277B93E10706B1614972B2A94C7310FE9C708C231A1A8AC8D9314A529A97F469BF64962D820648443099A076D55D4CEA824A58304844F99497C10A25148618A315D72CA857D1B04D575B94F85C01D19BEF211BF0AA3362E7041FD16596D808E867B44C4C00D1CDA3418967717F147D0EB21B42AAEE74AC35D0B92414B958531AADF463EC6305AE5ECAF79174002F26DDECC813BF32672E8529D95A4E730A7AB4A3E8F8A8AF979A665EAFD465FC64A0C5F8F3F9003489415899D59A543D8208C54A3166529B53922").unwrap(),
        "lhs: computed public key hash, rhs: hash from kat"
    );
    assert_eq!(
        secret_key.as_ref(), 
        hex::decode("07638FB69868F3D320E5862BD96933FEB311B362093C9B5D50170BCED43F1B536D9A204BB1F22695950BA1F2A9E8EB828B284488760B3FC84FABA04275D5628E39C5B2471374283C503299C0AB49B66B8BBB56A4186624F919A2BA59BB08D8551880C2BEFC4F87F25F59AB587A79C327D792D54C974A69262FF8A78938289E9A87B688B083E0595FE218B6BB1505941CE2E81A5A64C5AAC60417256985349EE47A52420A5F97477B7236AC76BC70E8288729287EE3E34A3DBC3683C0B7B10029FC203418537E7466BA6385A8FF301EE12708F82AAA1E380FC7A88F8F205AB7E88D7E95952A55BA20D09B79A47141D62BF6EB7DD307B08ECA13A5BC5F6B68581C6865B27BBCDDAB142F4B2CBFF488C8A22705FAA98A2B9EEA3530C76662335CC7EA3A00777725EBCCCD2A4636B2D9122FF3AB77123CE0883C1911115E50C9E8A94194E48DD0D09CFFB3ADCD2C1E92430903D07ADBF00532031575AA7F9E7B5A1F3362DEC936D4043C05F2476C07578BC9CBAF2AB4E382727AD41686A96B2548820BB03B32F11B2811AD62F489E951632ABA0D1DF89680CC8A8B53B481D92A68D70B4EA1C3A6A561C0692882B5CA8CC942A8D495AFCB06DE89498FB935B775908FE7A03E324D54CC19D4E1AABD3593B38B19EE1388FE492B43127E5A504253786A0D69AD32601C28E2C88504A5BA599706023A61363E17C6B9BB59BDC697452CD059451983D738CA3FD034E3F5988854CA05031DB09611498988197C6B30D258DFE26265541C89A4B31D6864E9389B03CB74F7EC4323FB9421A4B9790A26D17B0398A26767350909F84D57B6694DF830664CA8B3C3C03ED2AE67B89006868A68527CCD666459AB7F056671000C6164D3A7F266A14D97CBD7004D6C92CACA770B844A4FA9B182E7B18CA885082AC5646FCB4A14E1685FEB0C9CE3372AB95365C04FD83084F80A23FF10A05BF15F7FA5ACC6C0CB462C33CA524FA6B8BB359043BA68609EAA2536E81D08463B19653B5435BA946C9ADDEB202B04B031CC960DCC12E4518D428B32B257A4FC7313D3A7980D80082E934F9D95C32B0A0191A23604384DD9E079BBBAA266D14C3F756B9F2133107433A4E83FA7187282A809203A4FAF841851833D121AC383843A5E55BC2381425E16C7DB4CC9AB5C1B0D91A47E2B8DE0E582C86B6B0D907BB360B97F40AB5D038F6B75C814B27D9B968D419832BC8C2BEE605EF6E5059D33100D90485D378450014221736C07407CAC260408AA64926619788B8601C2A752D1A6CBF820D7C7A04716203225B3895B9342D147A8185CFC1BB65BA06B4142339903C0AC4651385B45D98A8B19D28CD6BAB088787F7EE1B12461766B43CBCCB96434427D93C065550688F6948ED1B5475A425F1B85209D061C08B56C1CC069F6C0A7C6F29358CAB911087732A649D27C9B98F9A48879387D9B00C25959A71654D6F6A946164513E47A75D005986C2363C09F6B537ECA78B9303A5FA457608A586A653A347DB04DFCC19175B3A301172536062A658A95277570C8852CA8973F4AE123A334047DD711C8927A634A03388A527B034BF7A8170FA702C1F7C23EC32D18A2374890BE9C787A9409C82D192C4BB705A2F996CE405DA72C2D9C843EE9F8313ECC7F86D6294D59159D9A879A542E260922ADF999051CC45200C9FFDB60449C49465979272367C083A7D6267A3ED7A7FD47957C219327F7CA73A4007E1627F00B11CC80573C15AEE6640FB8562DFA6B240CA0AD351AC4AC155B96C14C8AB13DD262CDFD51C4BB5572FD616553D17BDD430ACBEA3E95F0B698D66990AB51E5D03783A8B3D278A5720454CF9695CFDCA08485BA099C51CD92A7EA7587C1D15C28E609A81852601B0604010679AA482D51261EC36E36B8719676217FD74C54786488F4B4969C05A8BA27CA3A77CCE73B965923CA554E422B9B61F4754641608AC16C9B8587A32C1C5DD788F88B36B717A46965635DEB67F45B129B99070909C93EB80B42C2B3F3F70343A7CF37E8520E7BCFC416ACA4F18C7981262BA2BFC756AE03278F0EC66DC2057696824BA6769865A601D7148EF6F54E5AF5686AA2906F994CE38A5E0B938F239007003022C03392DF3401B1E4A3A7EBC6161449F73374C8B0140369343D9295FDF511845C4A46EBAAB6CA5492F6800B98C0CC803653A4B1D6E6AAED1932BACC5FEFAA818BA502859BA5494C5F5402C8536A9C4C1888150617F80098F6B2A99C39BC5DC7CF3B5900A21329AB59053ABAA64ED163E859A8B3B3CA3359B750CCC3E710C7AC43C8191CB5D68870C06391C0CB8AEC72B897AC6BE7FBAACC676ED66314C83630E89448C88A1DF04ACEB23ABF2E409EF333C622289C18A2134E650C45257E47475FA33AA537A5A8F7680214716C50D470E3284963CA64F54677AEC54B5272162BF52BC8142E1D4183FC017454A6B5A496831759064024745978CBD51A6CEDC8955DE4CC6D363670A47466E82BE5C23603A17BF22ACDB7CC984AF08C87E14E27753CF587A8EC3447E62C649E887A67C36C9CE98721B697213275646B194F36758673A8ED11284455AFC7A8529F69C97A3C2D7B8C636C0BA55614B768E624E712930F776169B01715725351BC74B47395ED52B25A1313C95164814C34C979CBDFAB85954662CAB485E75087A98CC74BB82CA2D1B5BF2803238480638C40E90B43C7460E7AA917F010151FAB1169987B372ABB59271F7006C24E60236B84B9DDD600623704254617FB498D89E58B0368BCB2103E79353EB587860C1422E476162E425BC2381DB82C6592737E1DD602864B0167A71EC1F223305C02FE25052AF2B3B5A55A0D7A2022D9A798DC0C5874A98702AAF4054C5D80338A5248B5B7BD09C53B5E2A084B047D277A861B1A73BB51488DE04EF573C85230A0470B73175C9FA50594F66A5F50B4150054C93B68186F8B5CBC49316C8548A642B2B36A1D454C7489AC33B2D2CE6668096782A2C1E0866D21A65E16B585E7AF8618BDF3184C1986878508917277B93E10706B1614972B2A94C7310FE9C708C231A1A8AC8D9314A529A97F469BF64962D820648443099A076D55D4CEA824A58304844F99497C10A25148618A315D72CA857D1B04D575B94F85C01D19BEF211BF0AA3362E7041FD16596D808E867B44C4C00D1CDA3418967717F147D0EB21B42AAEE74AC35D0B92414B958531AADF463EC6305AE5ECAF79174002F26DDECC813BF32672E8529D95A4E730A7AB4A3E8F8A8AF979A665EAFD465FC64A0C5F8F3F9003489415899D59A543D8208C54A3166529B53922D4EC143B50F01423B177895EDEE22BB739F647ECF85F50BC25EF7B5A725DEE868626ED79D451140800E03B59B956F8210E556067407D13DC90FA9E8B872BFB8F").unwrap(),
        "lhs: computed secret key hash, rhs: hash from kat"
    );

    let (ciphertext, shared_secret) =
        mlkem768::encapsulate(key_pair.public_key(), hex::decode("147c03f7a5bebba406c8fae1874d7f13c80efe79a3a9a874cc09fe76f6997615").unwrap().try_into().unwrap());
    

    assert_eq!(
        ciphertext.as_ref(),
        hex::decode("B52C56B92A4B7CE9E4CB7C5B1B163167A8A1675B2FDEF84A5B67CA15DB694C9F11BD027C30AE22EC921A1D911599AF0585E48D20DA70DF9F39E32EF95D4C8F44BFEFDAA5DA64F1054631D04D6D3CFD0A540DD7BA3886E4B5F13E878788604C95C096EAB3919F427521419A946C26CC041475D7124CDC01D0373E5B09C7A70603CFDB4FB3405023F2264DC3F983C4FC02A2D1B268F2208A1F6E2A6209BFF12F6F465F0B069C3A7F84F606D8A94064003D6EC114C8E808D3053884C1D5A142FBF20112EB360FDA3F0F28B172AE50F5E7D83801FB3F0064B687187074BD7FE30EDDAA334CF8FC04FA8CED899CEADE4B4F28B68372BAF98FF482A415B731155B75CEB976BE0EA0285BA01A27F1857A8FB377A3AE0C23B2AA9A079BFABFF0D5B2F1CD9B718BEA03C42F343A39B4F142D01AD8ACBB50E38853CF9A50C8B44C3CF671A4A9043B26DDBB24959AD6715C08521855C79A23B9C3D6471749C40725BDD5C2776D43AED20204BAA141EFB3304917474B7F9F7A4B08B1A93DAED98C67495359D37D67F7438BEE5E43585634B26C6B3810D7CDCBC0F6EB877A6087E68ACB8480D3A8CF6900447E49B417F15A53B607A0E216B855970D37406870B4568722DA77A4084703816784E2F16BED18996532C5D8B7F5D214464E5F3F6E905867B0CE119E252A66713253544685D208E1723908A0CE97834652E08AE7BDC881A131B73C71E84D20D68FDEFF4F5D70CD1AF57B78E3491A9865942321800A203C05ED1FEEB5A28E584E19F6535E7F84E4A24F84A72DCAF5648B4A4235DD664464482F03176E888C28BFC6C1CB238CFFA35A321E71791D9EA8ED0878C61121BF8D2A4AB2C1A5E120BC40ABB1892D1715090A0EE48252CA297A99AA0E510CF26B1ADD06CA543E1C5D6BDCD3B9C585C8538045DB5C252EC3C8C3C954D9BE5907094A894E60EAB43538CFEE82E8FFC0791B0D0F43AC1627830A61D56DAD96C62958B0DE780B78BD47A604550DAB83FFF227C324049471F35248CFB849B25724FF704D5277AA352D550958BE3B237DFF473EC2ADBAEA48CA2658AEFCC77BBD4264AB374D70EAE5B964416CE8226A7E3255A0F8D7E2ADCA062BCD6D78D60D1B32E11405BE54B66EF0FDDD567702A3BCCFEDE3C584701269ED14809F06F8968356BB9267FE86E514252E88BB5C30A7ECB3D0E621021EE0FBF7871B09342BF84F55C97EAF86C48189C7FF4DF389F077E2806E5FA73B3E9458A16C7E275F4F602275580EB7B7135FB537FA0CD95D6EA58C108CD8943D70C1643111F4F01CA8A8276A902666ED81B78D168B006F16AAA3D8E4CE4F4D0FB0997E41AEFFB5B3DAA838732F357349447F387776C793C0479DE9E99498CC356FDB0075A703F23C55D47B550EC89B02ADE89329086A50843456FEDC3788AC8D97233C54560467EE1D0F024B18428F0D73B30E19F5C63B9ABF11415BEA4D0170130BAABD33C05E6524E5FB5581B22B0433342248266D0F1053B245CC2462DC44D34965102482A8ED9E4E964D5683E5D45D0C8269").unwrap(),
        "lhs: computed ciphertext hash, rhs: hash from akt"
    );
    assert_eq!(
        shared_secret.as_ref(),
        hex::decode("914CB67FE5C38E73BF74181C0AC50428DEDF7750A98058F7D536708774535B29").unwrap(),
        "lhs: computed shared secret from encapsulate, rhs: shared secret from kat"
    );

    let shared_secret_from_decapsulate = mlkem768::decapsulate(key_pair.private_key(), &ciphertext);
    assert_eq!(shared_secret_from_decapsulate, shared_secret.as_ref(), "lhs: shared secret computed via decapsulation, rhs: shared secret computed via encapsulation");
}
