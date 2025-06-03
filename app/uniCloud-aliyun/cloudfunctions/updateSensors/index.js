exports.main = async (event, context) => {
  const db = uniCloud.database()
  const { deviceId, sensorId, newValue } = event

  const res = await db.collection('devices').doc(deviceId).update({
    "sensorList": db.command.set(
      db.command.aggregate.map({
        input: '$sensorList',
        as: 'item',
        in: db.command.aggregate.cond(
          { $eq: ['$$item.id', sensorId] },
          { ...db.command.aggregate.mergeObjects('$$item'), value: newValue },
          '$$item'
        )
      })
    )
  })

  return res
}